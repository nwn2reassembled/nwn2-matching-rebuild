"""Versioned, evidence-gated native units. Independent implementation; no dispatch.

Validation establishes consistency of supplied evidence, not its historical truth.
Review records must be authored outside the candidate's trust boundary.
"""
import json
from pathlib import Path, PurePosixPath
import re

from matching import sha256, verify_file

HEX = re.compile(r'[0-9a-f]{64}')
EVIDENCE_KINDS = {'boundary', 'abi', 'binding', 'placement', 'not-applicable'}
REGION_KINDS = {'function', 'funclet', 'handler', 'code', 'data', 'eh-table', 'tls'}
BINDING_KINDS = {'function', 'data', 'iat-slot', 'runtime', 'vtable', 'tls'}
FLAGS = {'/O1', '/O2', '/Od', '/Ob0', '/Ob1', '/Ob2', '/Oy', '/Oy-', '/GS', '/GS-',
         '/EHsc', '/EHs', '/EHs-c-', '/Gy', '/GF', '/MT', '/MD', '/fp:fast', '/fp:precise'}


def digest(value):
    return sha256(json.dumps(value, sort_keys=True, separators=(',', ':'),
                             allow_nan=False).encode())


def require(condition, message):
    if not condition:
        raise ValueError(message)


def number(value, minimum=0, maximum=0xffffffff):
    require(type(value) is int and minimum <= value <= maximum, 'Invalid bounded integer')
    return value


def hash_value(value):
    require(isinstance(value, str) and HEX.fullmatch(value), 'Expected SHA-256')
    return value


def text(value):
    require(isinstance(value, str) and value.strip() and '\0' not in value, 'Expected nonempty text')
    return value


def safe_path(root, relative):
    """Read only regular files under an explicit root; reject every symlink hop."""
    text(relative)
    path = PurePosixPath(relative)
    require(not path.is_absolute() and '\\' not in relative and
            all(p not in ('', '.', '..') for p in relative.split('/')), 'Unsafe input path')
    current = Path(root).resolve()
    for part in path.parts:
        current = current / part
        require(not current.is_symlink(), 'Symlink input forbidden')
    require(current.is_file(), 'Input is not a regular file')
    return current


def validate_unit(unit):
    require(unit['schema_version'] == 1 and type(unit['schema_version']) is int, 'Unsupported unit schema')
    text(unit['id'])
    target = unit['target']
    text(target['name'])
    number(target['size'], 1)
    hash_value(target['sha256'])
    base = number(target['image_base'])
    files = unit['files']
    require(isinstance(files, dict) and files, 'Input files required')
    for key, item in files.items():
        text(key)
        hash_value(item['sha256'])
        # Path existence/hash is checked by validate_inputs, not schema validation.
        path = item['path']
        require(isinstance(path, str) and path and not PurePosixPath(path).is_absolute()
                and '\\' not in path and all(p not in ('', '.', '..') for p in path.split('/')),
                'Unsafe manifest input path')
        require(item['role'] in {'source', 'header', 'evidence', 'compiler', 'sdk', 'backend'}, 'Unknown input role')
    recipe = unit['recipe']
    for role in ('compiler', 'sdk', 'backend'):
        require(recipe[role] in files and files[recipe[role]]['role'] == role, 'Missing toolchain input')
    require(any(f['role'] == 'source' for f in files.values()), 'Source input required')
    require(recipe['environment'] == 'isolated-no-network-no-secrets', 'Unsafe build environment policy')
    require(isinstance(recipe['flags'], list) and all(f in FLAGS for f in recipe['flags']), 'Unsupported compiler flag')
    evidence = unit['evidence']
    for key, item in evidence.items():
        text(key)
        require(item['kind'] in EVIDENCE_KINDS and item['review_state'] == 'reviewed', 'Unreviewed evidence')
        require(item['derivation'] in {'independent-observation', 'synthetic-specification'},
                'Inferred/reference-operand-only evidence is not acceptance evidence')
        text(item['reviewer'])
        text(item['description'])
        require(item['file'] in files and files[item['file']]['role'] == 'evidence', 'Missing evidence file')
        number(item['line_start'], 1)
        number(item['line_end'], item['line_start'])

    def proof(refs, kind):
        require(isinstance(refs, list) and refs and len(refs) == len(set(refs)), 'Evidence references required')
        require(all(ref in evidence and evidence[ref]['kind'] == kind for ref in refs), 'Wrong/missing evidence kind')

    bindings = unit['bindings']
    for symbol, item in bindings.items():
        text(symbol)
        require(item['artifact_sha256'] == target['sha256'] and item['scope'] == unit['id'], 'Binding scope/pin mismatch')
        require(item['kind'] in BINDING_KINDS, 'Unknown binding kind')
        number(item['va'], base)
        proof(item['evidence'], 'binding')
    regions = unit['regions']
    require(isinstance(regions, list) and regions, 'Explicit owned regions required')
    ids = [r['id'] for r in regions]
    require(len(ids) == len(set(ids)), 'Duplicate region identity')
    by_id = {r['id']: r for r in regions}
    for region in regions:
        text(region['id'])
        text(region['symbol'])
        require(region['kind'] in REGION_KINDS, 'Unknown region kind')
        number(region['section'], 1, 65535)
        offset = number(region['object_offset'])
        size = number(region['size'], 1)
        rva = number(region['rva'])
        require(max(offset + size, base + rva + size) <= 0x100000000, 'Region range overflow')
        proof(region['boundary_evidence'], 'boundary')
        proof(region['placement_evidence'], 'placement')
        if region['kind'] in {'function', 'funclet', 'handler', 'code'}:
            proof(region['abi_evidence'], 'abi')
        require(isinstance(region['dependencies'], list) and len(region['dependencies']) == len(set(region['dependencies'])),
                'Malformed dependency closure')
        require(all(d in bindings or d in by_id for d in region['dependencies']), 'Missing dependency')
        if 'alias_of' in region:
            primary = by_id.get(region['alias_of'])
            require(primary is not None and primary is not region and 'alias_of' not in primary
                    and (primary['rva'], primary['size'], primary['kind']) == (rva, size, region['kind']),
                    'Invalid folded alias')
        for other in regions:
            if other is region:
                break
            overlap = rva < other['rva'] + other['size'] and other['rva'] < rva + size
            allowed = region.get('alias_of') == other['id'] or other.get('alias_of') == region['id']
            allowed |= bool(region.get('alias_of') and region.get('alias_of') == other.get('alias_of'))
            require(not overlap or allowed, 'Overlapping original range ownership')
            require(not (region['section'] == other['section'] and offset < other['object_offset'] + other['size']
                         and other['object_offset'] < offset + size), 'Overlapping object ownership')
    require(len({r['symbol'] for r in regions}) == len(regions), 'Ambiguous region symbol')
    closures = unit['eh_closures']
    require(len({c['id'] for c in closures}) == len(closures), 'Duplicate EH closure')
    roles = {'parent', 'handler', 'funclets', 'unwind', 'types', 'catches', 'destructors', 'runtime', 'cookie'}
    for closure in closures:
        text(closure['id'])
        require(set(closure['roles']) == roles, 'Incomplete EH role declaration')
        owned = set()
        parents = []
        for role, record in closure['roles'].items():
            if 'not_applicable' in record:
                require(role != 'parent' and set(record) == {'not_applicable'}, 'Invalid EH exemption')
                proof(record['not_applicable'], 'not-applicable')
            else:
                require(set(record) == {'regions'} and record['regions'] and
                        len(record['regions']) == len(set(record['regions'])) and
                        all(r in by_id for r in record['regions']), 'Missing EH owned regions')
                owned.update(record['regions'])
                expected = {'parent': {'function'}, 'handler': {'handler'}, 'funclets': {'funclet'},
                            'unwind': {'eh-table'}, 'types': {'eh-table'}, 'catches': {'eh-table'},
                            'destructors': {'function', 'code'}, 'runtime': {'function', 'code'},
                            'cookie': {'function', 'code', 'data'}}[role]
                require(all(by_id[r]['kind'] in expected for r in record['regions']), 'Wrong EH role region kind')
                if role == 'parent':
                    parents = record['regions']
        require(len(parents) == 1, 'EH closure needs one explicit parent')
        reachable, pending = set(), list(parents)
        while pending:
            rid = pending.pop()
            if rid not in reachable:
                reachable.add(rid)
                pending.extend(d for d in by_id[rid]['dependencies'] if d in by_id)
        require(owned <= reachable, 'EH region absent from parent dependency graph')
    for annotation in unit.get('names', []):
        text(annotation['name'])
        number(annotation['rva'])
        require(annotation['source'] in {'OBSERVED_ORIGINAL', 'INDEPENDENT_ABI', 'COMPILER_GENERATED',
                                         'COMMUNITY_NAME', 'GUESS'}, 'Unknown name provenance')
        require(annotation['confidence'] in {'high', 'medium', 'low'}, 'Missing name confidence')
        require(annotation['evidence'] and all(r in evidence for r in annotation['evidence']),
                'Name annotation needs evidence; names are never binding proof')
    return unit


def validate_inputs(unit, root):
    validate_unit(unit)
    for item in unit['files'].values():
        path = safe_path(root, item['path'])
        require(sha256(path.read_bytes()) == item['sha256'], 'Stale source/tool/evidence input: ' + item['path'])
    for item in unit['evidence'].values():
        path = safe_path(root, unit['files'][item['file']]['path'])
        require(item['line_end'] <= len(path.read_bytes().splitlines()), 'Evidence line range exceeds file')


def verify_reference(unit, reference):
    """Always pin the entire file, including bytes outside compared regions."""
    target = unit['target']
    return verify_file(reference, {'size': target['size'], 'sha256': target['sha256']})
