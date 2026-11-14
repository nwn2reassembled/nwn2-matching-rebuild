"""Materialize reviewed original-site regions. No reference bytes are inputs.

Only DIR32, REL32 and DIR32NB are supported. TLS/SECREL and inferred placements
remain explicit blockers. This is neither an object normalizer nor a PE linker.
"""
import struct

from matching import sha256
from native_unit import require, validate_unit


def validate_structure(obj):
    """Additional strict lane gate; leave legacy leaf parser behavior unchanged."""
    _, count, _, symbol_offset, symbol_count, _, _ = struct.unpack_from('<HHIIIHH', obj.data)
    spans = [(0, 20 + count * 40)]
    strings = symbol_offset + symbol_count * 18
    string_size = struct.unpack_from('<I', obj.data, strings)[0]
    spans.append((symbol_offset, strings + string_size))
    for index in range(count):
        _, _, _, size, raw, reloc, line, nreloc, nline, _ = struct.unpack_from('<8sIIIIIIHHI', obj.data, 20 + index * 40)
        require(not line and not nline, 'COFF line tables not supported in strict native lane')
        if raw and size:
            spans.append((raw, raw + size))
        if nreloc:
            spans.append((reloc, reloc + nreloc * 10))
    for index, (start, end) in enumerate(spans):
        require(0 <= start < end <= len(obj.data), 'Truncated native object table')
        require(not any(start < right and left < end for left, right in spans[:index]),
                'Overlapping COFF structural ranges')


def materialize(obj, unit):
    validate_unit(unit)
    validate_structure(obj)
    base = unit['target']['image_base']
    regions = unit['regions']
    symbols = {s['index']: s for s in obj.symbols}
    require(len(symbols) == len(obj.symbols), 'Duplicate COFF symbol index')
    placements = {}
    for region in regions:
        matches = [s for s in obj.symbols if s['name'] == region['symbol']]
        require(len(matches) == 1, 'Missing/ambiguous region symbol')
        symbol = matches[0]
        require((symbol['section_number'], symbol['value']) == (region['section'], region['object_offset']),
                'Object symbol disagrees with explicit placement')
        require(region['section'] <= len(obj.sections), 'Missing object section')
        section = obj.sections[region['section'] - 1]
        require(section['file_offset'] and region['object_offset'] + region['size'] <= section['size'],
                'Region not file-backed')
        if region['kind'] in {'function', 'funclet', 'handler', 'code'}:
            require(section['executable'], 'Code region not executable')
            if region['kind'] == 'function':
                require(symbol['type'] & 0x30 == 0x20, 'Function lacks COFF function type')
            require(not symbol['function_aux_size'] or symbol['function_aux_size'] == region['size'],
                    'Conflicting COFF auxiliary size')
            require(not any(s['section_number'] == region['section'] and s['type'] & 0x30 == 0x20
                            and region['object_offset'] < s['value'] < region['object_offset'] + region['size']
                            for s in obj.symbols), 'Nested function entry requires separate ownership')
        placements[region['id']] = region

    def resolve(symbol, addend, source):
        require(symbol['aux_count'] == 0 or symbol['section_number'] > 0, 'Unsupported external auxiliary symbols')
        require(sum(s['name'] == symbol['name'] for s in obj.symbols) == 1, 'Ambiguous target symbol')
        if symbol['section_number'] == 0:
            require(symbol['storage_class'] == 2 and symbol['value'] == 0, 'Unsupported external/common target')
            require(symbol['name'] in unit['bindings'] and symbol['name'] in source['dependencies'],
                    'External target missing reviewed dependency binding')
            binding = unit['bindings'][symbol['name']]
            target = binding['va'] + addend
            require(0 <= target <= 0xffffffff, 'Target address overflow')
            return target, {'binding': symbol['name'], 'kind': binding['kind'], 'evidence': binding['evidence']}
        require(symbol['section_number'] > 0, 'Absolute/debug symbols require explicit reviewed bindings')
        target_offset = symbol['value'] + addend
        owners = [r for r in regions if r['section'] == symbol['section_number'] and
                  r['object_offset'] <= target_offset < r['object_offset'] + r['size']]
        require(len(owners) == 1, 'Local target outside uniquely owned region')
        owner = owners[0]
        require(owner['id'] == source['id'] or owner['id'] in source['dependencies'], 'Undeclared local dependency')
        return base + owner['rva'] + target_offset - owner['object_offset'], {'region': owner['id']}

    outputs, fixups = {}, []
    for region in regions:
        section = obj.sections[region['section'] - 1]
        start, end = region['object_offset'], region['object_offset'] + region['size']
        raw = section['file_offset'] + start
        result = bytearray(obj.data[raw:raw + region['size']])
        occupied = set()
        for relocation in section['relocations']:
            kind, offset = relocation['type'], relocation['offset']
            if kind == 0:
                continue
            require(kind in (6, 7, 20), 'Unsupported relocation kind (including TLS/SECREL)')
            require(0 <= offset and offset + 4 <= section['size'], 'Relocation exceeds raw section')
            if offset + 4 <= start or offset >= end:
                continue
            require(start <= offset and offset + 4 <= end, 'Relocation straddles region boundary')
            field = set(range(offset, offset + 4))
            require(not occupied & field, 'Overlapping relocation fields')
            occupied |= field
            require(relocation['symbol_index'] in symbols, 'Auxiliary/invalid relocation target')
            symbol = symbols[relocation['symbol_index']]
            # COFF i386 addends are signed for REL32; DIR32/DIR32NB use raw u32.
            addend = struct.unpack_from('<i' if kind == 20 else '<I', obj.data,
                                        section['file_offset'] + offset)[0]
            target, evidence = resolve(symbol, addend, region)
            site = base + region['rva'] + offset - start
            value = target - (site + 4) if kind == 20 else target - base if kind == 7 else target
            require((-0x80000000 <= value <= 0x7fffffff) if kind == 20 else (0 <= value <= 0xffffffff),
                    'Relocation arithmetic overflow')
            struct.pack_into('<I', result, offset - start, value & 0xffffffff)
            fixups.append({'region': region['id'], 'offset': offset - start, 'type': kind,
                           'symbol': symbol['name'], 'site_va': site, 'target_va': target,
                           'addend': addend, 'encoded_value': value & 0xffffffff, 'evidence': evidence})
        outputs[region['id']] = bytes(result)
    return outputs, {'object_sha256': sha256(obj.data), 'fixups': fixups,
                     'normalization': 'none', 'reference_operands_read': False}
