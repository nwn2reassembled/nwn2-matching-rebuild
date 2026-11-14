import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
import zipfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import bootstrap
import compile_lane
import workflow as w


class WorkflowTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for name in ('state', 'exchange', 'output', 'work'):
            p = self.root / name; p.mkdir()
            patcher = patch.object(w, {'state': 'STATE', 'exchange': 'EXCHANGE', 'output': 'OUTPUT', 'work': 'WORK'}[name], p)
            patcher.start(); self.addCleanup(patcher.stop)
        env = patch.dict(os.environ, {'TASK_ID': 'rules-smoke-04270', 'PROVIDER': 'deepseek',
            'MODEL': 'test-model', 'MAX_TOKENS': '512', 'DEEPSEEK_API_KEY': 'fake-key-for-tests',
            'SEND_REFERENCE_TO_PROVIDER': 'yes'})
        env.start(); self.addCleanup(env.stop)
        self.task = w.selected_task(); self.folder = w.EXCHANGE / self.task['id']; self.folder.mkdir()
        self.packet = {'task': self.task, 'identity': 'a'*64, 'prompt': 'Synthetic prompt; no original bytes'}
        w.write_new(self.folder / 'packet.json', self.packet)
        self.source = 'struct X { int f(); };\nint X::f() { return 1; }\n'

    def generate(self):
        return patch.object(w, 'generate', return_value={'source': self.source, 'usage': {}})

    def test_one_request_then_saved_reuse(self):
        with self.generate() as api:
            self.assertEqual(w.draft()['status'], 'drafted')
            self.assertEqual(w.draft()['status'], 'saved-draft-reused-no-request')
            self.assertEqual(api.call_count, 1)

    def test_interrupted_request_never_retried(self):
        with patch.object(w, 'generate', side_effect=TimeoutError('sensitive response')) as api:
            with self.assertRaises(RuntimeError): w.draft()
            with self.assertRaises(ValueError): w.draft()
            self.assertEqual(api.call_count, 1)
        self.assertNotIn('sensitive', (self.folder / 'draft-failure.json').read_text())

    def test_token_exhaustion_never_continued(self):
        from providers import TokenBudgetExhausted
        with patch.object(w, 'generate', side_effect=TokenBudgetExhausted('closed')) as api:
            with self.assertRaises(RuntimeError): w.draft()
            with self.assertRaises(ValueError): w.draft()
            self.assertEqual(api.call_count, 1)

    def test_restart_with_new_model_does_not_reset_budget(self):
        with self.generate() as api:
            w.draft()
            with patch.dict(os.environ, {'MODEL': 'another-model'}):
                with self.assertRaises(ValueError): w.draft()
            self.assertEqual(api.call_count, 1)

    def test_consent_required_before_paid_call(self):
        with patch.dict(os.environ, {'SEND_REFERENCE_TO_PROVIDER': 'no'}), self.generate() as api:
            with self.assertRaises(ValueError): w.draft()
            api.assert_not_called()
        self.assertFalse((self.folder / 'request-started.json').exists())

    def test_missing_key_does_not_consume_request(self):
        with patch.dict(os.environ, {'DEEPSEEK_API_KEY': ''}), self.generate() as api:
            with self.assertRaises(ValueError): w.draft()
            api.assert_not_called()
        self.assertFalse((self.folder / 'request-started.json').exists())

    def test_invalid_output_closes_attempt_without_source(self):
        with patch.object(w, 'generate', return_value={'source': 'int X::f(){return 1;} // private', 'usage': {}}):
            with self.assertRaises(RuntimeError): w.draft()
        self.assertFalse((self.folder / 'candidate.cpp').exists())

    def test_source_changed_after_paid_call_is_rejected(self):
        with self.generate(): w.draft()
        (self.folder / 'candidate.cpp').write_text(self.source + ' ')
        with self.generate() as api:
            with self.assertRaises(ValueError): w.draft()
            api.assert_not_called()

    def test_unknown_or_path_task_rejected(self):
        for identity in ('../escape', 'nonexistent', 'x'*65):
            with patch.dict(os.environ, {'TASK_ID': identity}):
                with self.assertRaises(ValueError): w.selected_task()

    def test_strict_source_filter(self):
        for payload in ('#include <a>', 'asm("x")', '// comment', '\\x90', '\x00', '/* comment */'):
            with self.assertRaises(ValueError): w.source_check(self.source + payload)

    def test_synthetic_disassembly_and_escape_checks(self):
        self.assertIn('ret', w.assembly_packet(b'\x90\x90\x90\xc3', {'rva': '0x1000'}))
        for code in (b'\xeb\x7f\xc3', b'\xe8\x00\x00\x00\x00\xc3', b'\xff\xe0', b'\x90'):
            with self.assertRaises(ValueError): w.assembly_packet(code, {'rva': '0x1000'})

    def setup_verification(self):
        with self.generate(): w.draft()
        contract = w.read_json(w.ROOT / 'reference/toolchain.json')
        w.write_new(w.STATE / 'ready.json', {'toolchain_manifest_sha256': w.canonical_hash(contract)})
        checks = [{'exact': True, 'size': 13, 'relocations': [],
                   'function_sha256': '1'*64, 'object_sha256': c*64} for c in ('2', '3')]
        return checks

    def test_verified_pass_archive_is_hashes_and_source_only(self):
        checks = self.setup_verification()
        with patch.object(w, 'extract_function', return_value=(b'synthetic', {'relocations': []})), \
                patch.object(compile_lane, 'verify_source', return_value=checks):
            result = w.verify()
            self.assertEqual(result['status'], 'pass')
            self.assertFalse(result['automatic_project_credit'])
            with self.assertRaises(ValueError): w.verify()
        archive = w.OUTPUT / self.task['id'] / 'contribution.zip'
        with zipfile.ZipFile(archive) as z:
            names = {Path(n).name for n in z.namelist()}
            self.assertEqual(names, {'source.cpp', 'task.json', 'result.json', 'provenance.json'})
            data = b''.join(z.read(n) for n in z.namelist())
            for private in (b'Synthetic prompt', b'fake-key-for-tests', b'boundary_evidence'):
                self.assertNotIn(private, data)

    def test_mismatch_never_exports(self):
        checks = self.setup_verification(); checks[1]['exact'] = False
        with patch.object(w, 'extract_function', return_value=(b'synthetic', {'relocations': []})), \
                patch.object(compile_lane, 'verify_source', return_value=checks):
            self.assertEqual(w.verify()['status'], 'mismatch')
        self.assertFalse((w.OUTPUT / self.task['id'] / 'contribution.zip').exists())

    def test_compile_failure_saved_and_not_retried(self):
        self.setup_verification()
        with patch.object(w, 'extract_function', return_value=(b'synthetic', {'relocations': []})), \
                patch.object(compile_lane, 'verify_source', side_effect=RuntimeError('private logs')) as compile_fn:
            with self.assertRaises(RuntimeError): w.verify()
            with self.assertRaises(ValueError): w.verify()
            self.assertEqual(compile_fn.call_count, 1)
        self.assertNotIn('private logs', (w.OUTPUT / self.task['id'] / 'failure.json').read_text())

    def test_wine_environment_has_no_credentials(self):
        env = compile_lane.wine_environment(Path('/work/test'))
        for key in ('OPENAI_API_KEY', 'DEEPSEEK_API_KEY', 'ANTHROPIC_API_KEY', 'GITHUB_TOKEN', 'SSH_AUTH_SOCK'):
            self.assertNotIn(key, env)
        self.assertEqual(env['TEMP'], 'Z:\\work\\test\\temp')

    def test_wrong_sdk_rejected_before_extraction(self):
        iso = self.root / 'bad.iso'; iso.write_bytes(b'not-an-sdk')
        with patch.object(bootstrap, 'run') as extract:
            with self.assertRaises(ValueError):
                bootstrap.extract_sdk(iso, self.root / 'toolchain', self.root / 'scratch',
                    {'iso': {'size': 1, 'sha256': '0'*64}})
            extract.assert_not_called()

    def test_reference_requires_exact_hash_and_unique_filename(self):
        source = self.root / 'refs'; source.mkdir()
        (source / 'a.dll').write_bytes(b'synthetic')
        pins = {'a.dll': {'size': 9, 'sha256': bootstrap.digest(source / 'a.dll')}}
        self.assertEqual(bootstrap.find_references(source, pins)['a.dll'].name, 'a.dll')
        (source / 'A.DLL').write_bytes(b'synthetic')
        with self.assertRaises(ValueError): bootstrap.find_references(source, pins)

    def test_symlinked_reference_rejected(self):
        source = self.root / 'refs'; source.mkdir()
        original = self.root / 'original'; original.write_bytes(b'synthetic')
        (source / 'a.dll').symlink_to(original)
        with self.assertRaises(ValueError):
            bootstrap.find_references(source, {'a.dll': {'size': 9, 'sha256': bootstrap.digest(original)}})

    def test_redistributable_not_accepted_as_sdk(self):
        directory = self.root / 'gog'; directory.mkdir()
        with self.assertRaises(ValueError): bootstrap.extract_gog(directory, self.root / 'dest', {}, self.root)


if __name__ == '__main__':
    unittest.main()
