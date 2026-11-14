"""Read-only PE inspection and strict byte comparisons. No normalization."""
import argparse
from collections import Counter
import datetime
import hashlib
import importlib.metadata
import json
import os
from pathlib import Path
import platform
import struct
import sys

import pefile

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_REFERENCES = Path(os.environ.get('NWN2_REFERENCE_ROOT', str(ROOT / 'private/references')))


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def verify_file(path, pin):
    data = Path(path).read_bytes()
    actual = {'size': len(data), 'sha256': sha256(data)}
    if actual != pin:
        raise ValueError(f'Reference mismatch: {path}: {actual}; expected {pin}')
    return data


def compare_bytes(reference, candidate):
    common = min(len(reference), len(candidate))
    differing = [i for i in range(common) if reference[i] != candidate[i]]
    first = differing[0] if differing else (common if len(reference) != len(candidate) else None)
    return {
        'exact': reference == candidate,
        'reference_size': len(reference), 'candidate_size': len(candidate),
        'reference_sha256': sha256(reference), 'candidate_sha256': sha256(candidate),
        'equal_bytes_at_same_offset': common - len(differing),
        'different_bytes_including_missing': len(differing) + abs(len(reference) - len(candidate)),
        'first_mismatch': first,
    }


def rva_to_offset(pe, rva, size=1):
    """Reject virtual tails, truncated data, ambiguous mappings and cross-range reads."""
    if rva < 0 or size <= 0:
        raise ValueError('RVA must be nonnegative and size positive')
    mappings = []
    if rva + size <= pe.OPTIONAL_HEADER.SizeOfHeaders:
        mappings.append(rva)
    for section in pe.sections:
        delta = rva - section.VirtualAddress
        if 0 <= delta and delta + size <= section.SizeOfRawData:
            mappings.append(section.PointerToRawData + delta)
    if len(mappings) != 1 or mappings[0] + size > len(pe.__data__):
        raise ValueError(f'RVA range {rva:#x}+{size:#x} is not uniquely file-backed')
    return mappings[0]


def offset_to_rva(pe, offset, size=1):
    if offset < 0 or size <= 0 or offset + size > len(pe.__data__):
        raise ValueError('Invalid file range')
    mappings = []
    if offset + size <= pe.OPTIONAL_HEADER.SizeOfHeaders:
        mappings.append(offset)
    for section in pe.sections:
        delta = offset - section.PointerToRawData
        if 0 <= delta and delta + size <= section.SizeOfRawData:
            mappings.append(section.VirtualAddress + delta)
    if len(mappings) != 1:
        raise ValueError('File range is not uniquely mapped (overlay or certificate?)')
    return mappings[0]


def va_to_offset(pe, va, size=1):
    return rva_to_offset(pe, va - pe.OPTIONAL_HEADER.ImageBase, size)


def compare_regions(reference, candidate, reference_offset, candidate_offset, size):
    if size <= 0 or reference_offset < 0 or candidate_offset < 0:
        raise ValueError('Region size must be positive and offsets nonnegative')
    if reference_offset + size > len(reference) or candidate_offset + size > len(candidate):
        raise ValueError('Region exceeds file boundaries')
    return {'reference_file_offset': reference_offset, 'candidate_file_offset': candidate_offset,
            'size': size, 'comparison': compare_bytes(reference[reference_offset:reference_offset + size],
                                                    candidate[candidate_offset:candidate_offset + size]),
            'excluded_reference_ranges': [[0, reference_offset], [reference_offset + size, len(reference)]],
            'excluded_candidate_ranges': [[0, candidate_offset], [candidate_offset + size, len(candidate)]],
            'range_convention': 'half-open [start,end); empty excluded ranges contain no bytes',
            'exact_artifact_claim': False}


def relocation_overlaps(pe, rva, size):
    result = []
    for block in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', []):
        for item in block.entries:
            if item.type == 0:  # ABSOLUTE is padding, not a fixup
                continue
            width = {1: 2, 2: 2, 3: 4, 4: 2, 10: 8}.get(item.type)
            # Unknown types are conservatively retained for manual inspection.
            if width is None or item.rva < rva + size and item.rva + width > rva:
                result.append({'rva': item.rva, 'type': item.type, 'width': width})
    return result


def extract_function(path, pin, rva, size, boundary_evidence):
    if not boundary_evidence.strip():
        raise ValueError('Explicit boundary evidence required')
    data = verify_file(path, pin)
    pe = pefile.PE(data=data)
    offset = rva_to_offset(pe, rva, size)
    executable = any(s.Characteristics & 0x20000000 and
                     s.VirtualAddress <= rva and
                     rva + size <= s.VirtualAddress + s.SizeOfRawData for s in pe.sections)
    if not executable:
        raise ValueError('Function range is not in an executable section')
    result = data[offset:offset + size]
    return result, {'reference_sha256': pin['sha256'], 'rva': rva,
                    'va': pe.OPTIONAL_HEADER.ImageBase + rva, 'file_offset': offset,
                    'size': size, 'sha256': sha256(result),
                    'boundary_evidence': boundary_evidence,
                    'relocations': relocation_overlaps(pe, rva, size)}


def text(value):
    return value.decode('utf-8', errors='replace') if isinstance(value, bytes) else str(value)


def resource_inventory(pe):
    results = []

    def visit(directory, path):
        for entry in directory.entries:
            current = path + [str(entry.name) if entry.name is not None else entry.id]
            if hasattr(entry, 'directory'):
                visit(entry.directory, current)
            else:
                s = entry.data.struct
                offset = rva_to_offset(pe, s.OffsetToData, s.Size) if s.Size else None
                data = pe.__data__[offset:offset + s.Size] if s.Size else b''
                result = {'path': current, 'rva': s.OffsetToData, 'size': s.Size,
                          'codepage': s.CodePage, 'sha256': sha256(data)}
                if current[0] == 24:
                    result['manifest_text'] = text(data)
                results.append(result)

    if hasattr(pe, 'DIRECTORY_ENTRY_RESOURCE'):
        visit(pe.DIRECTORY_ENTRY_RESOURCE, [])
    return results


def inspect_pe(path, pin):
    data = verify_file(path, pin)
    pe = pefile.PE(data=data)
    oh = pe.OPTIONAL_HEADER
    rich = pe.parse_rich_header()
    versions = []
    for group in getattr(pe, 'FileInfo', []):
        for info in group:
            for table in getattr(info, 'StringTable', []):
                versions.append({text(k): text(v) for k, v in table.entries.items()})
    debug = []
    for entry in getattr(pe, 'DIRECTORY_ENTRY_DEBUG', []):
        s = entry.struct
        payload = data[s.PointerToRawData:s.PointerToRawData + s.SizeOfData]
        record = {'type': s.Type, 'size': s.SizeOfData, 'timestamp': s.TimeDateStamp,
                  'file_offset': s.PointerToRawData, 'sha256': sha256(payload)}
        if payload.startswith(b'RSDS') and len(payload) >= 24:
            import uuid
            record.update(guid=str(uuid.UUID(bytes_le=payload[4:20])),
                          age=struct.unpack_from('<I', payload, 20)[0],
                          pdb_path=text(payload[24:].split(b'\0')[0]))
        debug.append(record)
    clr = None
    directory = oh.DATA_DIRECTORY[14]
    if directory.VirtualAddress:
        offset = rva_to_offset(pe, directory.VirtualAddress, 72)
        fields = struct.unpack_from('<IHH' + 'I' * 16, data, offset)
        flags = fields[5]
        clr = {'header_size': fields[0], 'runtime_header_version': list(fields[1:3]),
               'metadata_rva': fields[3], 'metadata_size': fields[4],
               'flags': flags, 'il_only': bool(flags & 1),
               'requires_32bit': bool(flags & 2), 'strong_name_signed_flag': bool(flags & 8),
               'entrypoint_token_or_rva': fields[6],
               'resources_rva': fields[7], 'resources_size': fields[8],
               'strong_name_rva': fields[9], 'strong_name_size': fields[10],
               'signature_cryptographically_verified': False}
    imports = []
    for descriptor in getattr(pe, 'DIRECTORY_ENTRY_IMPORT', []):
        imports.append({'dll': text(descriptor.dll), 'symbols': [
            {'name': text(s.name) if s.name else None, 'ordinal': s.ordinal,
             'iat_va': s.address} for s in descriptor.imports]})
    exports = [{'name': text(s.name) if s.name else None, 'ordinal': s.ordinal,
                'rva': s.address, 'forwarder': text(s.forwarder) if s.forwarder else None}
               for s in getattr(getattr(pe, 'DIRECTORY_ENTRY_EXPORT', None), 'symbols', [])]
    sections = []
    for s in pe.sections:
        raw = data[s.PointerToRawData:s.PointerToRawData + s.SizeOfRawData]
        sections.append({'name': text(s.Name.rstrip(b'\0')), 'rva': s.VirtualAddress,
                         'virtual_size': s.Misc_VirtualSize, 'file_offset': s.PointerToRawData,
                         'raw_size': s.SizeOfRawData, 'characteristics': s.Characteristics,
                         'raw_sha256': sha256(raw)})
    values = rich['values'] if rich else []
    return {'filename': Path(path).name, **pin,
            'origin': {'documented': 'User-supplied local reference; verified against reference/pins.json',
                       'fresh_installer_verification': False, 'local_path': str(path)},
            'machine': pe.FILE_HEADER.Machine, 'characteristics': pe.FILE_HEADER.Characteristics,
            'timestamp': pe.FILE_HEADER.TimeDateStamp,
            'timestamp_utc_interpretation': datetime.datetime.fromtimestamp(pe.FILE_HEADER.TimeDateStamp, datetime.timezone.utc).isoformat(),
            'optional_header_magic': oh.Magic, 'linker_version': [oh.MajorLinkerVersion, oh.MinorLinkerVersion],
            'image_base': oh.ImageBase, 'entrypoint_rva': oh.AddressOfEntryPoint,
            'section_alignment': oh.SectionAlignment, 'file_alignment': oh.FileAlignment,
            'size_of_image': oh.SizeOfImage, 'dll_characteristics': oh.DllCharacteristics,
            'checksum_stored': oh.CheckSum, 'checksum_calculated': pe.generate_checksum(),
            'directories': [{'name': d.name, 'address': d.VirtualAddress, 'size': d.Size,
                             'address_kind': 'file_offset' if i == 4 else 'rva'}
                            for i, d in enumerate(oh.DATA_DIRECTORY)],
            'sections': sections, 'version_strings': versions,
            'fixed_version_info': [v.dump_dict() for v in getattr(pe, 'VS_FIXEDFILEINFO', [])],
            'imports': imports, 'exports': exports, 'resources': resource_inventory(pe),
            'debug': debug, 'clr': clr,
            'rich_entries': [{'product_id': values[i] >> 16, 'build': values[i] & 65535,
                              'count': values[i + 1]} for i in range(0, len(values), 2)],
            'relocations': [{'page_rva': b.struct.VirtualAddress,
                             'block_size': b.struct.SizeOfBlock,
                             'entry_count': len(b.entries),
                             'type_counts': dict(Counter(e.type for e in b.entries)),
                             'block_sha256': sha256(data[b.struct.get_file_offset():b.struct.get_file_offset() + b.struct.SizeOfBlock])}
                            for b in getattr(pe, 'DIRECTORY_ENTRY_BASERELOC', [])],
            'overlay_offset': pe.get_overlay_data_start_offset(), 'parser_warnings': pe.get_warnings()}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    subs = parser.add_subparsers(dest='command', required=True)
    scan = subs.add_parser('inventory')
    scan.add_argument('--references', type=Path, default=DEFAULT_REFERENCES)
    scan.add_argument('--output', type=Path, required=True)
    check = subs.add_parser('verify')
    check.add_argument('--references', type=Path, default=DEFAULT_REFERENCES)
    diff = subs.add_parser('compare')
    diff.add_argument('reference', type=Path)
    diff.add_argument('candidate', type=Path)
    diff.add_argument('--pinned-name', required=True, help='Reference filename in reference/pins.json')
    region = subs.add_parser('region')
    region.add_argument('reference', type=Path)
    region.add_argument('candidate', type=Path)
    region.add_argument('--pinned-name', required=True)
    region.add_argument('--reference-offset', type=lambda v: int(v, 0), required=True)
    region.add_argument('--candidate-offset', type=lambda v: int(v, 0), required=True)
    region.add_argument('--size', type=lambda v: int(v, 0), required=True)
    extract = subs.add_parser('extract')
    extract.add_argument('--references', type=Path, default=DEFAULT_REFERENCES)
    extract.add_argument('--pinned-name', required=True)
    extract.add_argument('--rva', type=lambda v: int(v, 0), required=True)
    extract.add_argument('--size', type=lambda v: int(v, 0), required=True)
    extract.add_argument('--boundary-evidence', required=True)
    extract.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    pins = json.loads((ROOT / 'reference/pins.json').read_text())
    if args.command == 'extract':
        data, metadata = extract_function(args.references / args.pinned_name, pins[args.pinned_name],
                                          args.rva, args.size, args.boundary_evidence)
        args.output.parent.mkdir(parents=True, exist_ok=True)
        if args.output.exists():
            raise ValueError('Refusing to overwrite existing extraction output')
        args.output.write_bytes(data)
        print(json.dumps(metadata, indent=2))
        return 0
    if args.command == 'region':
        result = compare_regions(verify_file(args.reference, pins[args.pinned_name]),
                                 args.candidate.read_bytes(), args.reference_offset,
                                 args.candidate_offset, args.size)
        print(json.dumps(result, indent=2))
        return 0 if result['comparison']['exact'] else 1
    if args.command == 'compare':
        result = compare_bytes(verify_file(args.reference, pins[args.pinned_name]), args.candidate.read_bytes())
        print(json.dumps(result, indent=2))
        return 0 if result['exact'] else 1
    if args.command == 'verify':
        for name, pin in pins.items():
            verify_file(args.references / name, pin)
            print(f'VERIFIED {name} {pin["sha256"]}')
        return 0
    result = {'schema_version': 1, 'tools': {'python': platform.python_version(),
              'pefile': importlib.metadata.version('pefile')},
              'files': [inspect_pe(args.references / name, pin) for name, pin in pins.items()]}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(f'Verified and inventoried {len(pins)} references: {args.output}')
    return 0


if __name__ == '__main__':
    try:
        sys.exit(main())
    except (ValueError, OSError, KeyError, pefile.PEFormatError) as exc:
        print(str(exc), file=sys.stderr)
        sys.exit(2)
