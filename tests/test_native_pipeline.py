"""Independently authored COFF/PE fixtures; no game payload or compiler execution."""
import copy
import json
from pathlib import Path
import struct
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from coff_object import CoffObject
from matching import sha256
from native_placement import materialize
from native_journal import append_event, create_journal, read_journal
from native_unit import digest, safe_path, validate_inputs, validate_unit
from native_verify import validate_receipt, verify_unit
from native_workflow import (assess_plan, attempt_transition, context_pack, coverage,
                             project_scope, regression_plan, route)


def coff(code, relocations=(), symbols=None):
    symbols = symbols or [('leaf', 0, 1, 0x20), ('global', 0, 0, 0), ('callee', 0, 0, 0x20)]
    records = b''.join(struct.pack('<IIH', *r) for r in relocations)
    symbol_data = b''.join(struct.pack('<8sIhHBB', name.encode(), offset, section, kind, 2, 0)
                           for name, offset, section, kind in symbols)
    header = struct.pack('<HHIIIHH', 0x14c, 1, 0, 60 + len(code) + len(records), len(symbols), 0, 0)
    section = struct.pack('<8sIIIIIIHHI', b'.text', 0, 0, len(code), 60,
                          60 + len(code) if records else 0, 0, len(relocations), 0, 0x60000020)
    return header + section + code + records + symbol_data + struct.pack('<I', 4)


def pe_image(code):
    image = bytearray(1024)
    image[:2] = b'MZ'
    struct.pack_into('<I', image, 0x3c, 0x80)
    image[0x80:0x84] = b'PE\0\0'
    struct.pack_into('<HHIIIHH', image, 0x84, 0x14c, 1, 0, 0, 0, 224, 0x102)
    optional = 0x98
    struct.pack_into('<H', image, optional, 0x10b)
    for offset, value in ((16, 0x1000), (20, 0x1000), (28, 0x400000), (32, 0x1000),
                          (36, 0x200), (56, 0x2000), (60, 0x200), (92, 16)):
        struct.pack_into('<I', image, optional + offset, value)
    struct.pack_into('<8sIIIIIIHHI', image, optional + 224, b'.text', 0x200, 0x1000,
                     0x200, 0x200, 0, 0, 0, 0, 0x60000020)
    image[0x200:0x200 + len(code)] = code
    return bytes(image)


def unit_fixture(root, code=b'\xb8\0\0\0\0\xe8\0\0\0\0\xc3'):
    contents = {'source': ('unit.cpp', b'// synthetic fixture only\n'),
                'evidence': ('review.txt', b'Synthetic independent specification\n'),
                'compiler': ('cl.fixture', b'not an executable'),
                'sdk': ('sdk.fixture', b'synthetic sdk identity'),
                'backend': ('backend.fixture', b'no execution')}
    files = {}
    for role, (path, data) in contents.items():
        (root / path).write_bytes(data)
        files[role] = {'path': path, 'sha256': sha256(data), 'role': role}
    image = pe_image(code)
    reference = root / 'synthetic.exe'
    reference.write_bytes(image)
    evidence = {kind: {'kind': kind, 'review_state': 'reviewed', 'reviewer': 'synthetic-test',
                       'derivation': 'synthetic-specification', 'description': 'Synthetic fixture specification',
                       'file': 'evidence', 'line_start': 1, 'line_end': 1}
                for kind in ('boundary', 'abi', 'binding', 'placement', 'not-applicable')}
    target = {'name': 'synthetic.exe', 'size': len(image), 'sha256': sha256(image), 'image_base': 0x400000}
    unit = {'schema_version': 1, 'id': 'synthetic-unit', 'target': target, 'files': files,
            'recipe': {'compiler': 'compiler', 'sdk': 'sdk', 'backend': 'backend', 'flags': ['/O2'],
                       'environment': 'isolated-no-network-no-secrets'}, 'evidence': evidence,
            'bindings': {}, 'regions': [{'id': 'main', 'symbol': 'leaf', 'section': 1,
                'object_offset': 0, 'rva': 0x1000, 'size': len(code), 'kind': 'function',
                'boundary_evidence': ['boundary'], 'placement_evidence': ['placement'],
                'abi_evidence': ['abi'], 'dependencies': ['global', 'callee']}], 'eh_closures': []}
    for name, va in (('global', 0x401100), ('callee', 0x401080)):
        unit['bindings'][name] = {'va': va, 'kind': 'data' if name == 'global' else 'function',
                                 'artifact_sha256': target['sha256'], 'scope': unit['id'], 'evidence': ['binding']}
    return unit, reference


class NativeTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.unit, self.reference = unit_fixture(self.root)
        self.code = b'\xb8\0\0\0\0\xe8\0\0\0\0\xc3'
        self.object = coff(self.code, ((1, 1, 6), (6, 2, 20)))

    def verify(self, unit=None, object_data=None):
        unit = unit or self.unit
        return verify_unit(unit, object_data or self.object, self.reference, self.root,
                           {unit['target']['name']: {k: unit['target'][k] for k in ('size', 'sha256')}}, digest(unit))

    def retarget(self, code):
        image = pe_image(code)
        self.reference.write_bytes(image)
        self.unit['target'].update(size=len(image), sha256=sha256(image))
        for b in self.unit['bindings'].values():
            b['artifact_sha256'] = sha256(image)

    def test_schema_and_inputs(self):
        validate_inputs(self.unit, self.root)
        (self.root / 'unit.cpp').write_text('changed')
        with self.assertRaises(ValueError):
            validate_inputs(self.unit, self.root)

    def test_scope_review_hypothesis_and_unsafe_flags_fail(self):
        for edit in (lambda u: u['bindings']['global'].update(scope='elsewhere'),
                     lambda u: u['bindings']['global'].update(artifact_sha256='0' * 64),
                     lambda u: u['evidence']['binding'].update(review_state='hypothesis'),
                     lambda u: u['evidence']['binding'].update(derivation='reference-operand-inference'),
                     lambda u: u['recipe'].update(flags=['/FIsecret.h']),
                     lambda u: u['regions'][0].update(abi_evidence=[]),
                     lambda u: u['regions'][0].update(boundary_evidence=['abi'])):
            unit = copy.deepcopy(self.unit)
            edit(unit)
            with self.assertRaises(ValueError):
                validate_unit(unit)

    def test_escape_and_symlink_inputs_rejected(self):
        for name in ('../secret', '/etc/passwd', 'x/../unit.cpp', 'x\\unit.cpp', './unit.cpp'):
            with self.assertRaises(ValueError):
                safe_path(self.root, name)
        (self.root / 'link.cpp').symlink_to(self.root / 'unit.cpp')
        with self.assertRaises(ValueError):
            safe_path(self.root, 'link.cpp')

    def test_materializes_all_bytes_without_mutation(self):
        obj = CoffObject(self.object)
        before = obj.data
        result, meta = materialize(obj, self.unit)
        self.assertEqual(result['main'], b'\xb8\x00\x11\x40\x00\xe8\x76\x00\x00\x00\xc3')
        self.assertEqual(obj.data, before)
        self.assertFalse(meta['reference_operands_read'])
        with self.assertRaises(ValueError):
            obj.extract('leaf', 11, 'still unresolved')

    def test_signed_relative_addends_both_directions(self):
        for target, addend in ((0x400f00, -4), (0x401080, 4)):
            self.unit['bindings']['callee']['va'] = target
            raw = self.code[:6] + struct.pack('<i', addend) + b'\xc3'
            result, _ = materialize(CoffObject(coff(raw, ((6, 2, 20),))), self.unit)
            self.assertEqual(struct.unpack_from('<i', result['main'], 6)[0], target + addend - 0x40100a)

    def test_dir32nb_independent_base(self):
        result, _ = materialize(CoffObject(coff(self.code, ((1, 1, 7),))), self.unit)
        self.assertEqual(struct.unpack_from('<I', result['main'], 1)[0], 0x1100)

    def test_dir32_addend_overflow_and_alternate_iat_target_fail(self):
        raw = b'\xb8\xff\xff\xff\xff' + self.code[5:]
        with self.assertRaises(ValueError):
            materialize(CoffObject(coff(raw, ((1, 1, 6),))), self.unit)
        expected, _ = materialize(CoffObject(self.object), self.unit)
        self.retarget(expected['main'])
        self.unit['bindings']['global'].update(va=0x401104, kind='iat-slot')
        self.assertFalse(self.verify()['all_regions_exact'])

    def test_structural_table_overlap_and_truncated_auxiliary_rejected(self):
        raw = bytearray(self.object)
        struct.pack_into('<I', raw, 20 + 24, 60)  # Relocation table over raw code.
        with self.assertRaises(ValueError):
            materialize(CoffObject(raw), self.unit)
        raw = bytearray(self.object)
        symbol_offset = struct.unpack_from('<I', raw, 8)[0]
        raw[symbol_offset + 17] = 99
        with self.assertRaises(ValueError):
            CoffObject(raw)

    def test_name_guesses_remain_annotations_not_bindings(self):
        self.unit['names'] = [{'name': 'hypotheticalAccessor', 'rva': 0x1000, 'source': 'GUESS',
                               'confidence': 'low', 'evidence': ['abi']}]
        validate_unit(self.unit)
        self.assertEqual(context_pack(self.unit)['names'][0]['source'], 'GUESS')
        self.unit['names'][0]['confidence'] = 'certain'
        with self.assertRaises(ValueError):
            validate_unit(self.unit)

    def test_straddle_overlap_unsupported_aux_and_overflow(self):
        cases = [((9, 1, 6),), ((1, 1, 6), (2, 2, 20)), ((1, 1, 11),), ((1, 1, 0x7777),)]
        for relocations in cases:
            with self.assertRaises(ValueError):
                materialize(CoffObject(coff(self.code, relocations)), self.unit)
        obj = CoffObject(self.object)
        obj.symbols[1]['index'] = 99
        with self.assertRaises(ValueError):
            materialize(obj, self.unit)
        self.unit['bindings']['callee']['va'] = 0xffffffff
        with self.assertRaises(ValueError):
            materialize(CoffObject(self.object), self.unit)

    def test_missing_dependency_and_out_of_region_local_target(self):
        self.unit['regions'][0]['dependencies'].remove('callee')
        with self.assertRaises(ValueError):
            materialize(CoffObject(self.object), self.unit)
        self.unit['regions'][0]['dependencies'].append('callee')
        obj = CoffObject(self.object)
        obj.symbols[2].update(section_number=1, value=100)
        with self.assertRaises(ValueError):
            materialize(obj, self.unit)

    def test_bounded_local_target(self):
        obj = CoffObject(self.object)
        obj.symbols[2].update(section_number=1, value=10, type=0)
        result, _ = materialize(obj, self.unit)
        self.assertEqual(struct.unpack_from('<i', result['main'], 6)[0], 0)

    def test_auxiliary_size_nested_entry_and_region_overlap(self):
        for edit in (lambda obj: obj.symbols[0].update(function_aux_size=10),
                     lambda obj: obj.symbols[2].update(section_number=1, value=10)):
            obj = CoffObject(self.object)
            edit(obj)
            with self.assertRaises(ValueError):
                materialize(obj, self.unit)
        region = dict(self.unit['regions'][0], id='overlap', symbol='other', object_offset=20)
        self.unit['regions'].append(region)
        with self.assertRaises(ValueError):
            validate_unit(self.unit)

    def test_unmasked_comparison_and_no_credit(self):
        result, _ = materialize(CoffObject(self.object), self.unit)
        self.retarget(result['main'])
        receipt = self.verify()
        self.assertTrue(receipt['all_regions_exact'])
        self.assertFalse(receipt['exact_artifact'])
        self.assertFalse(receipt['integration_credit'])
        validate_receipt(receipt, self.unit)
        altered = bytearray(result['main'])
        altered[1] ^= 1  # One byte inside a relocation field must NOT be ignored.
        self.retarget(bytes(altered))
        self.assertFalse(self.verify()['all_regions_exact'])

    def test_whole_file_pin_outside_function_and_parent_digest(self):
        image = bytearray(self.reference.read_bytes())
        image[-1] ^= 1
        self.reference.write_bytes(image)
        with self.assertRaises(ValueError):
            self.verify()
        with self.assertRaises(ValueError):
            verify_unit(self.unit, self.object, self.reference, self.root, {}, '0' * 64)

    def test_wrong_image_base_and_trusted_pin_reject(self):
        self.unit['target']['image_base'] += 0x1000
        with self.assertRaises(ValueError):
            self.verify()
        with self.assertRaises(ValueError):
            verify_unit(self.unit, self.object, self.reference, self.root, {}, digest(self.unit))

    def test_alias_secondary_mismatch(self):
        code = b'\x90\xc3\x91\xc3'
        self.unit['regions'][0].update(size=2, dependencies=[])
        self.unit['regions'].append(dict(self.unit['regions'][0], id='alias', symbol='alias',
                                          object_offset=2, alias_of='main'))
        self.retarget(code)
        obj = coff(code, symbols=[('leaf', 0, 1, 0x20), ('alias', 2, 1, 0x20)])
        receipt = self.verify(object_data=obj)
        self.assertTrue(receipt['regions']['main']['comparison']['exact'])
        self.assertFalse(receipt['regions']['alias']['comparison']['exact'])
        self.assertFalse(receipt['all_regions_exact'])

    def test_eh_parent_tail_and_missing_roles(self):
        code = b'\x90\xc3\xcc\xc3'
        self.unit['regions'][0].update(size=2, dependencies=[])
        self.unit['regions'].append(dict(self.unit['regions'][0], id='tail', symbol='tail',
                                          object_offset=2, rva=0x1002, kind='funclet'))
        roles = {r: {'not_applicable': ['not-applicable']} for r in
                 ('handler', 'unwind', 'types', 'catches', 'destructors', 'runtime', 'cookie')}
        roles.update(parent={'regions': ['main']}, funclets={'regions': ['tail']})
        self.unit['regions'][0]['dependencies'] = ['tail']
        self.unit['eh_closures'] = [{'id': 'eh', 'roles': roles}]
        self.retarget(code)
        for candidate in (b'\x90\xc3\x90\xc3', b'\x91\xc3\xcc\xc3'):
            receipt = self.verify(object_data=coff(candidate, symbols=[('leaf', 0, 1, 0x20), ('tail', 2, 1, 0)]))
            self.assertFalse(receipt['eh_closures']['eh']['exact'])
        del roles['cookie']
        with self.assertRaises(ValueError):
            validate_unit(self.unit)

    def test_stale_receipt_source_verifier_and_tamper(self):
        receipt = self.verify()
        changed = copy.deepcopy(self.unit)
        changed['recipe']['flags'].append('/Gy')
        with self.assertRaises(ValueError):
            validate_receipt(receipt, changed)
        for field in ('unit_sha256', 'verifier', 'target'):
            bad = copy.deepcopy(receipt)
            bad[field] = 'tampered'
            with self.assertRaises(ValueError):
                validate_receipt(bad, self.unit)

    def test_context_is_hashed_and_contains_no_bodies(self):
        pack = context_pack(self.unit)
        self.assertNotIn('bodies', pack)
        recorded = pack.pop('context_sha256')
        self.assertEqual(recorded, digest(pack))

    def test_planner_rebuilds_header_recipe_and_uncertain_changes(self):
        units = {self.unit['id']: self.unit}
        self.assertEqual(regression_plan(units, units)['affected'], [])
        for changed in (['unit.cpp'], ['unknown-header.h']):
            self.assertEqual(regression_plan(units, units, changed)['affected'], [self.unit['id']])
        new = copy.deepcopy(self.unit)
        new['recipe']['flags'] = ['/Od']
        plan = regression_plan(units, {new['id']: new})
        self.assertTrue(plan['conservative_full_rebuild'])
        self.assertEqual(regression_plan(units, units, discovery_uncertain=True)['affected'], [self.unit['id']])

    def test_missing_shards_regression_and_duplicate_receipt_no_ledger_write(self):
        units = {self.unit['id']: self.unit}
        plan = regression_plan({}, units)
        with self.assertRaises(ValueError):
            assess_plan(plan, units, {})
        receipts = {self.unit['id']: self.verify()}
        result = assess_plan(plan, units, receipts)
        self.assertEqual(result['state'], 'integration-regression')
        self.assertFalse(result['baseline_modified'])
        self.assertEqual(assess_plan(plan, units, receipts), result)

    def test_exact_shards_still_require_independent_parent_review(self):
        expected, _ = materialize(CoffObject(self.object), self.unit)
        self.retarget(expected['main'])
        units = {self.unit['id']: self.unit}
        result = assess_plan(regression_plan({}, units), units, {self.unit['id']: self.verify()})
        self.assertEqual(result['state'], 'ready-for-independent-parent-review')
        self.assertFalse(result['integration_credit'])

    def test_project_scope_reads_current_ledger_without_mutation(self):
        (self.root / 'progress').mkdir()
        (self.root / 'reference').mkdir()
        item = {'id': 'synthetic:native:1000', 'kind': 'native-function', 'binary': 'synthetic.exe',
                'rva': '0x1000', 'status': 'ready'}
        queue = json.dumps({'items': [item]}).encode()
        (self.root / 'queue.json').write_bytes(queue)
        policy = {'queue': 'queue.json', 'queue_sha256': sha256(queue), 'known_items': 1}
        (self.root / 'progress/full_corpus01.json').write_text(json.dumps(policy))
        pins = {'synthetic.exe': {k: self.unit['target'][k] for k in ('size', 'sha256')}}
        (self.root / 'reference/pins.json').write_text(json.dumps(pins))
        record = {'binary': 'synthetic.exe', 'binary_sha256': self.unit['target']['sha256'],
                  'rva': '0x1000', 'reference_instruction_bytes': 11, 'raw_function_match': True}
        ledger = {'functions': [record], 'source_derived_exact_function_count': 1,
                  'source_derived_exact_instruction_bytes': 11}
        ledger_path = self.root / 'progress/functions.json'
        ledger_path.write_text(json.dumps(ledger))
        original = ledger_path.read_bytes()
        result = project_scope(self.root)
        self.assertEqual(result['known_items'], 1)
        self.assertEqual(result['unique_bytes'], 11)
        self.assertEqual(ledger_path.read_bytes(), original)
        ledger['functions'].append(record)
        ledger['source_derived_exact_function_count'] = 2
        ledger['source_derived_exact_instruction_bytes'] = 22
        ledger_path.write_text(json.dumps(ledger))
        with self.assertRaises(ValueError):
            project_scope(self.root)

    def test_routing_respects_readiness_and_history_before_size(self):
        self.assertEqual(route(self.unit, idle=True, spent=True)['action'], 'preserve-no-replay')
        self.assertEqual(route(self.unit, idle=True, uncertain=True)['action'], 'preserve-no-replay')
        self.assertEqual(route(self.unit, idle=True, declarations_ready=False)['action'], 'dependency-repair')
        self.assertEqual(route(self.unit, idle=False)['requests_consumed'], 0)
        self.assertFalse(route(self.unit, idle=True)['dispatch_enabled'])

    def test_budget_wait_crash_and_exhaustion_no_reset(self):
        state = {'state': 'planned', 'submission_limit': 3, 'requests_sent': 0,
                 'request_ids': [], 'outstanding': None, 'context_sha256': 'context'}
        self.assertEqual(attempt_transition(state, {'kind': 'waiting'})['requests_sent'], 0)
        event = {'kind': 'request-sent', 'request_id': 'one', 'context_sha256': 'context'}
        pending = attempt_transition(state, event)
        persisted = json.loads(json.dumps(pending))  # Simulate restart with durable state.
        with self.assertRaises(ValueError):
            attempt_transition(persisted, event)
        for result in ('output-token-exhausted', 'uncertain-request'):
            terminal = attempt_transition(pending, {'kind': 'response', 'request_id': 'one', 'result': result})
            with self.assertRaises(ValueError):
                attempt_transition(terminal, dict(event, request_id='two'))
        state = {'kind': 'response', 'request_id': 'one', 'result': 'ordinary-mismatch'}
        current = attempt_transition(pending, state)
        for request in ('two', 'three'):
            current = attempt_transition(current, dict(event, request_id=request))
            current = attempt_transition(current, dict(state, request_id=request))
        self.assertEqual(current['state'], 'budget-exhausted')
        with self.assertRaises(ValueError):
            attempt_transition(current, dict(event, request_id='four'))

    def test_union_coverage_aliases_and_logical_tokens(self):
        items = [{'id': 'method:1', 'status': 'unattempted'}, {'id': 'method:2', 'status': 'unattempted'}]
        record = {'binary': 'one', 'artifact_sha256': 'a' * 64, 'rva': 10, 'size': 10,
                  'kind': 'function', 'independently_verified': True}
        result = coverage(items, [record, record, dict(record, rva=15)])
        self.assertEqual(result['known_items'], 2)
        self.assertEqual(result['unique_bytes'], 15)
        self.assertEqual(result['unique_function_entries'], 2)
        with self.assertRaises(ValueError):
            coverage(items + [items[0]], [])
        with self.assertRaises(ValueError):
            coverage(items, [dict(record, independently_verified=False)])

    def test_journal_crash_persists_budget_and_rejects_overwrite(self):
        path = self.root / 'attempt.jsonl'
        state = create_journal(path, 'synthetic-attempt', 'a' * 64)
        with self.assertRaises(FileExistsError):
            create_journal(path, 'synthetic-attempt', 'a' * 64)
        event = {'kind': 'request-sent', 'request_id': 'one', 'context_sha256': 'a' * 64}
        pending = append_event(path, event, digest(state))
        self.assertEqual(read_journal(path), pending)
        with self.assertRaises(ValueError):
            append_event(path, event, digest(state))
        exhausted = append_event(path, {'kind': 'response', 'request_id': 'one',
                                       'result': 'output-token-exhausted'}, digest(pending))
        self.assertEqual(read_journal(path)['requests_sent'], 1)
        with self.assertRaises(ValueError):
            append_event(path, dict(event, request_id='two'), digest(exhausted))

    def test_partial_journal_blocks_not_rolls_back(self):
        path = self.root / 'attempt.jsonl'
        create_journal(path, 'synthetic-attempt', 'a' * 64)
        with path.open('a') as stream:
            stream.write('{"partial":')
        with self.assertRaises(ValueError):
            read_journal(path)


if __name__ == '__main__':
    unittest.main()
