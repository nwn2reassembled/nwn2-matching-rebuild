"""Strict conventional i386 COFF object inspection. No linking or relocation masking.

Function extraction requires an explicit instruction size and boundary evidence;
a COMDAT section's length is not automatically treated as a function boundary.
BigObj, archives and PE executables are deliberately unsupported.
"""
import argparse
import json
from pathlib import Path
import struct
import sys

from matching import ROOT, compare_bytes, extract_function, sha256


class CoffObject:
    def __init__(self, data):
        self.data = bytes(data)
        self._range(0, 20)
        machine, count, timestamp, symbols_offset, symbols_count, optional_size, characteristics = struct.unpack_from('<HHIIIHH', self.data)
        if machine != 0x14c or not count or optional_size:
            raise ValueError('Expected conventional i386 COFF object, not PE/BigObj/archive')
        self.timestamp = timestamp
        self.characteristics = characteristics
        self._range(20, count * 40)
        self.headers_end = 20 + count * 40
        self.symbols_offset = symbols_offset
        self.symbols_count = symbols_count
        if not symbols_offset or symbols_offset < self.headers_end:
            raise ValueError('Missing/invalid COFF symbol table')
        self._range(symbols_offset, symbols_count * 18 + 4)
        string_offset = symbols_offset + symbols_count * 18
        string_size = struct.unpack_from('<I', self.data, string_offset)[0]
        if string_size < 4:
            raise ValueError('Invalid COFF string table size')
        self._range(string_offset, string_size)
        self.strings = self.data[string_offset:string_offset + string_size]
        self.sections = []
        raw_ranges = []
        for i in range(count):
            values = struct.unpack_from('<8sIIIIIIHHI', self.data, 20 + i * 40)
            name, virtual_size, virtual_address, size, offset, relocations_offset, line_offset, relocations_count, line_count, flags = values
            if virtual_address:
                raise ValueError('Unexpected nonzero object-section virtual address')
            if flags & 0x01000000:
                raise ValueError('Extended COFF relocation counts unsupported')
            if size and offset:
                self._range(offset, size)
                if offset < self.headers_end or offset + size > symbols_offset:
                    raise ValueError('Section raw data overlaps headers/symbol table')
                if any(offset < end and offset + size > start for start, end in raw_ranges):
                    raise ValueError('Overlapping COFF section data')
                raw_ranges.append((offset, offset + size))
            elif size and not flags & 0x80:
                raise ValueError('Non-BSS section lacks raw data')
            if relocations_count:
                self._range(relocations_offset, relocations_count * 10)
                if relocations_offset < self.headers_end or relocations_offset + relocations_count * 10 > symbols_offset:
                    raise ValueError('Invalid relocation table placement')
            relocations = []
            for j in range(relocations_count):
                address, symbol_index, kind = struct.unpack_from('<IIH', self.data, relocations_offset + j * 10)
                if symbol_index >= symbols_count:
                    raise ValueError('Relocation refers past symbol table')
                relocations.append({'offset': address, 'symbol_index': symbol_index, 'type': kind})
            self.sections.append({'number': i + 1, 'name': self._section_name(name),
                                  'size': size, 'file_offset': offset, 'characteristics': flags,
                                  'executable': bool(flags & 0x20000000), 'relocations': relocations})
        self.symbols = []
        index = 0
        while index < symbols_count:
            offset = symbols_offset + index * 18
            name, value, section, kind, storage, aux_count = struct.unpack_from('<8sIhHBB', self.data, offset)
            if index + aux_count >= symbols_count or section > count:
                raise ValueError('Invalid auxiliary-symbol count or section index')
            total_size = None
            if kind & 0x30 == 0x20 and storage == 2 and aux_count:
                total_size = struct.unpack_from('<I', self.data, offset + 18 + 4)[0]
            self.symbols.append({'index': index, 'name': self._symbol_name(name), 'value': value,
                                 'section_number': section, 'type': kind, 'storage_class': storage,
                                 'aux_count': aux_count, 'function_aux_size': total_size})
            index += 1 + aux_count

    def _range(self, offset, size):
        if offset < 0 or size < 0 or offset + size > len(self.data):
            raise ValueError('Truncated/out-of-range COFF data')

    def _string(self, offset):
        if not 4 <= offset < len(self.strings):
            raise ValueError('COFF string offset outside string table')
        end = self.strings.find(b'\0', offset)
        if end < 0:
            raise ValueError('Unterminated COFF string')
        return self.strings[offset:end].decode('utf-8', errors='replace')

    def _symbol_name(self, raw):
        if raw[:4] == b'\0' * 4:
            return self._string(struct.unpack_from('<I', raw, 4)[0])
        return raw.rstrip(b'\0').decode('utf-8', errors='replace')

    def _section_name(self, raw):
        if raw.startswith(b'/'):
            try:
                offset = int(raw[1:].rstrip(b'\0').decode('ascii'))
            except ValueError as exc:
                raise ValueError('Invalid long COFF section name') from exc
            return self._string(offset)
        return raw.rstrip(b'\0').decode('utf-8', errors='replace')

    def extract(self, name, size, boundary_evidence):
        if size <= 0 or not boundary_evidence.strip():
            raise ValueError('Positive instruction size and explicit boundary evidence required')
        symbols = [s for s in self.symbols if s['name'] == name and s['section_number'] > 0]
        if len(symbols) != 1:
            raise ValueError('Function symbol missing or ambiguous')
        symbol = symbols[0]
        if symbol['type'] & 0x30 != 0x20:
            raise ValueError('Selected symbol is not typed as a COFF function')
        section = self.sections[symbol['section_number'] - 1]
        start = symbol['value']
        if not section['executable'] or not section['file_offset'] or start + size > section['size']:
            raise ValueError('Function exceeds executable raw section')
        if symbol['function_aux_size'] and symbol['function_aux_size'] != size:
            raise ValueError('Explicit size disagrees with COFF function auxiliary size')
        if any(s['section_number'] == symbol['section_number'] and s['type'] & 0x30 == 0x20
               and start < s['value'] < start + size for s in self.symbols):
            raise ValueError('Extraction includes another function entry')
        overlaps = []
        for relocation in section['relocations']:
            if relocation['type'] == 0:
                continue
            width = {1: 2, 2: 2, 6: 4, 7: 4, 10: 2, 11: 4, 13: 1, 20: 4}.get(relocation['type'])
            if width is None or relocation['offset'] < start + size and relocation['offset'] + width > start:
                overlaps.append({**relocation, 'width': width})
        # Include any fixup touching the range, not just one starting in it.
        if overlaps:
            raise ValueError(f'Unresolved/overlapping COFF fixups: {overlaps}')
        offset = section['file_offset'] + start
        code = self.data[offset:offset + size]
        return code, {'object_sha256': sha256(self.data), 'symbol': symbol,
                      'section': section['name'], 'file_offset': offset, 'size': size,
                      'sha256': sha256(code), 'boundary_evidence': boundary_evidence,
                      'object_relocations': [], 'normalization': 'none'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('object', type=Path)
    parser.add_argument('--symbol')
    parser.add_argument('--size', type=lambda v: int(v, 0))
    parser.add_argument('--boundary-evidence')
    parser.add_argument('--reference', type=Path)
    parser.add_argument('--pinned-name')
    parser.add_argument('--reference-rva', type=lambda v: int(v, 0))
    parser.add_argument('--reference-size', type=lambda v: int(v, 0))
    parser.add_argument('--reference-boundary-evidence')
    args = parser.parse_args()
    obj = CoffObject(args.object.read_bytes())
    if args.symbol is None:
        print(json.dumps({'sha256': sha256(obj.data), 'sections': obj.sections, 'symbols': obj.symbols}, indent=2))
        return
    if args.size is None or args.boundary_evidence is None:
        parser.error('Extraction needs --size and --boundary-evidence')
    code, result = obj.extract(args.symbol, args.size, args.boundary_evidence)
    if args.reference:
        if not args.pinned_name or args.reference_rva is None or args.reference_size is None or not args.reference_boundary_evidence:
            parser.error('Comparison requires pinned name, reference RVA, reference size and reference boundary evidence')
        pins = json.loads((ROOT / 'reference/pins.json').read_text())
        reference, metadata = extract_function(args.reference, pins[args.pinned_name], args.reference_rva,
                                               args.reference_size, args.reference_boundary_evidence)
        result['reference'] = metadata
        result['comparison'] = compare_bytes(reference, code)
        result['exact_artifact'] = False
    print(json.dumps(result, indent=2))
    if args.reference and not result['comparison']['exact']:
        raise SystemExit(1)


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, KeyError, struct.error) as exc:
        print(str(exc), file=sys.stderr)
        sys.exit(2)
