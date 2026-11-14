"""Read-only verification of an explicit native unit against whole-file pins.

Does not compile, execute, promote, refresh RAG, or grant integration credit.
Trusted pins and evidence roots must be supplied by the parent, not a PR payload.
"""
import json
from pathlib import Path

import pefile

from coff_object import CoffObject
from matching import compare_bytes, rva_to_offset, sha256
from native_placement import materialize
from native_unit import digest, require, validate_inputs, verify_reference

VERIFIER_FILES = ('native_unit.py', 'native_placement.py', 'native_verify.py',
                  'coff_object.py', 'matching.py', 'native_workflow.py', 'native_tools.py',
                  'native_journal.py')


def verifier_identity():
    root = Path(__file__).resolve().parent
    return {'files': {name: sha256((root / name).read_bytes()) for name in VERIFIER_FILES},
            'pefile_version': pefile.__version__}


def verify_unit(unit, object_data, reference, input_root, trusted_pins, approved_unit_sha256):
    require(digest(unit) == approved_unit_sha256, 'Unit lacks exact parent-approved context digest')
    validate_inputs(unit, input_root)
    target = unit['target']
    pin = {'size': target['size'], 'sha256': target['sha256']}
    require(trusted_pins.get(target['name']) == pin, 'Manifest does not match trusted project pins')
    # Materialization has no access to the reference or its operands.
    candidate, relocation = materialize(CoffObject(object_data), unit)
    data = verify_reference(unit, reference)
    pe = pefile.PE(data=data)
    try:
        require(pe.FILE_HEADER.Machine == 0x14c and pe.OPTIONAL_HEADER.Magic == 0x10b,
                'Expected pinned i386 PE32 reference')
        require(pe.OPTIONAL_HEADER.ImageBase == target['image_base'], 'Wrong image base')
        results = {}
        for region in unit['regions']:
            offset = rva_to_offset(pe, region['rva'], region['size'])
            if region['kind'] in {'function', 'funclet', 'handler', 'code'}:
                require(any(s.Characteristics & 0x20000000 and s.VirtualAddress <= region['rva'] and
                            region['rva'] + region['size'] <= s.VirtualAddress + s.SizeOfRawData
                            for s in pe.sections), 'Code is not executable in reference')
            results[region['id']] = {'rva': region['rva'], 'size': region['size'], 'kind': region['kind'],
                                     'comparison': compare_bytes(data[offset:offset + region['size']],
                                                                 candidate[region['id']])}
        closure_results = {}
        for closure in unit['eh_closures']:
            owned = {rid for role in closure['roles'].values() for rid in role.get('regions', [])}
            closure_results[closure['id']] = {'regions': sorted(owned),
                                             'exact': all(results[r]['comparison']['exact'] for r in owned)}
        exact = all(r['comparison']['exact'] for r in results.values())
        receipt = {'schema_version': 1, 'unit': unit['id'], 'unit_sha256': digest(unit),
                   'input_sha256': {k: v['sha256'] for k, v in unit['files'].items()},
                   'target': pin, 'verifier': verifier_identity(), 'relocation': relocation,
                   'regions': results, 'eh_closures': closure_results,
                   'state': 'local-exact-awaiting-independent-verification' if exact else 'ordinary-mismatch',
                   'all_regions_exact': exact, 'normalization': 'none',
                   'compiler_execution_attested': False, 'independently_verified': False,
                   'integration_credit': False, 'exact_artifact': False}
        receipt['receipt_sha256'] = digest(receipt)
        return receipt
    finally:
        pe.close()


def validate_receipt(receipt, unit):
    """Reject stale/tampered receipts; this is consistency, not authentication."""
    validate = dict(receipt)
    recorded = validate.pop('receipt_sha256')
    require(digest(validate) == recorded, 'Receipt content changed')
    require(receipt['unit_sha256'] == digest(unit) and receipt['unit'] == unit['id'], 'Stale unit recipe')
    require(receipt['verifier'] == verifier_identity(), 'Stale verifier')
    require(receipt['input_sha256'] == {k: v['sha256'] for k, v in unit['files'].items()}, 'Stale inputs')
    require(receipt['target'] == {k: unit['target'][k] for k in ('size', 'sha256')}, 'Stale target')
    require(set(receipt['regions']) == {r['id'] for r in unit['regions']}, 'Missing/extra region results')
    for region in unit['regions']:
        result = receipt['regions'][region['id']]
        require((result['rva'], result['size'], result['kind']) == (region['rva'], region['size'], region['kind']),
                'Receipt range disagreement')
        comp = result['comparison']
        require(comp['reference_size'] == region['size'] and comp['candidate_size'] == region['size'],
                'Receipt size disagreement')
        require(comp['exact'] == (comp['reference_sha256'] == comp['candidate_sha256']), 'Inconsistent equality')
    exact = all(r['comparison']['exact'] for r in receipt['regions'].values())
    require(receipt['all_regions_exact'] == exact and receipt['normalization'] == 'none', 'Invalid equality summary')
    require(receipt['state'] == ('local-exact-awaiting-independent-verification' if exact else 'ordinary-mismatch'),
            'Invalid verification state')
    expected_closures = {}
    for closure in unit['eh_closures']:
        owned = {rid for role in closure['roles'].values() for rid in role.get('regions', [])}
        expected_closures[closure['id']] = {'regions': sorted(owned),
            'exact': all(receipt['regions'][r]['comparison']['exact'] for r in owned)}
    require(receipt['eh_closures'] == expected_closures, 'Inconsistent EH closure summary')
    require(receipt['integration_credit'] is False and receipt['exact_artifact'] is False and
            receipt['independently_verified'] is False and receipt['compiler_execution_attested'] is False,
            'Offline checker cannot grant parent/integration/compiler claims')
    return receipt
