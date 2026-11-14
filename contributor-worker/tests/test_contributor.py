import contextlib
import io
import json
import os
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch
import zipfile

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import providers
import contribution


class ProvidersTests(unittest.TestCase):
    def reply(self, data):
        return contextlib.closing(io.BytesIO(json.dumps(data).encode()))

    def test_openai_source_and_usage_without_credential_logging(self):
        opener = unittest.mock.Mock()
        opener.open.return_value = self.reply({'choices': [{'finish_reason': 'stop',
            'message': {'content': json.dumps({'source': 'int X::f(){return 1;}'})}}],
            'usage': {'prompt_tokens': 12, 'completion_tokens': 8, 'unsafe': 'secret'}})
        with patch.dict(os.environ, {'OPENAI_API_KEY': 'unit-test-key'}), \
                patch('providers.urllib.request.build_opener', return_value=opener):
            result = providers.generate('openai', 'explicit-model', 'Return source', 512)
        self.assertNotIn('unit-test-key', json.dumps(result))
        self.assertEqual(result['usage'], {'prompt_tokens': 12, 'completion_tokens': 8})
        self.assertEqual(opener.open.call_count, 1)
        payload = json.loads(opener.open.call_args.args[0].data)
        self.assertEqual(payload['max_completion_tokens'], 512)

    def test_anthropic_source(self):
        opener = unittest.mock.Mock()
        opener.open.return_value = self.reply({'stop_reason': 'end_turn',
            'content': [{'type': 'text', 'text': json.dumps({'source': 'int X::f(){return 1;}'})}],
            'usage': {'input_tokens': 12, 'output_tokens': 8}})
        with patch.dict(os.environ, {'ANTHROPIC_API_KEY': 'unit-test-key'}), \
                patch('providers.urllib.request.build_opener', return_value=opener):
            result = providers.generate('anthropic', 'explicit-model', 'Return source', 512)
        self.assertEqual(result['provider'], 'anthropic')
        self.assertEqual(result['usage']['output_tokens'], 8)
        self.assertNotIn('unit-test-key', json.dumps(result))

    def test_output_exhaustion_is_not_retried(self):
        opener = unittest.mock.Mock()
        opener.open.return_value = self.reply({'choices': [{'finish_reason': 'length',
            'message': {'content': 'partial source'}}]})
        with patch.dict(os.environ, {'OPENAI_API_KEY': 'unit-test-key'}), \
                patch('providers.urllib.request.build_opener', return_value=opener):
            with self.assertRaises(providers.TokenBudgetExhausted):
                providers.generate('openai', 'explicit-model', 'Return source')
        self.assertEqual(opener.open.call_count, 1)

    def test_deepseek_compatible_request_and_receipt(self):
        opener = unittest.mock.Mock()
        opener.open.return_value = self.reply({'choices': [{'finish_reason': 'stop',
            'message': {'content': json.dumps({'source': 'int X::f(){return 1;}'})}}],
            'usage': {'prompt_tokens': 20, 'completion_tokens': 10, 'total_tokens': 30}})
        with patch.dict(os.environ, {'DEEPSEEK_API_KEY': 'deepseek-unit-test-key'}), \
                patch('providers.urllib.request.build_opener', return_value=opener):
            result = providers.generate('deepseek', 'explicit-deepseek-model', 'Return source', 1024)
        request = opener.open.call_args.args[0]
        self.assertEqual(request.full_url, 'https://api.deepseek.com/chat/completions')
        payload = json.loads(request.data)
        self.assertEqual(payload['max_tokens'], 1024)
        self.assertNotIn('max_completion_tokens', payload)
        self.assertEqual(result['provider'], 'deepseek')
        self.assertEqual(result['usage']['total_tokens'], 30)
        self.assertNotIn('deepseek-unit-test-key', json.dumps(result))

    def test_credential_echo_is_never_returned(self):
        opener = unittest.mock.Mock()
        opener.open.return_value = self.reply({'error': 'unit-test-key'})
        with patch.dict(os.environ, {'OPENAI_API_KEY': 'unit-test-key'}), \
                patch('providers.urllib.request.build_opener', return_value=opener):
            with self.assertRaises(providers.ProviderError) as error:
                providers.generate('openai', 'explicit-model', 'Return source')
        self.assertNotIn('unit-test-key', str(error.exception))

    def test_redirect_rejects_credential_forwarding(self):
        with self.assertRaises(providers.ProviderError):
            providers.NoRedirect().redirect_request(None, None, 302, '', {}, 'https://other.invalid')


class ContributionTests(unittest.TestCase):
    def setUp(self):
        self.source = b'struct X { int f(); };\nint X::f(){return 1;}\n'
        self.task = {'binary': 'NWN2RulesLib.dll', 'binary_sha256': '1'*64,
                     'rva': '0x4270', 'size': 13, 'assembly': 'PRIVATE ASSEMBLY',
                     'original_bytes': 'PRIVATE BYTES'}
        self.result = {'status': 'pass', 'normalization': 'none',
            'source_sha256': contribution.digest(self.source),
            'compiler_arguments': contribution.FLAGS, 'toolchain_manifest_sha256': '2'*64,
            'generation': 'openai', 'stdout': 'PRIVATE LOG',
            'runs': [{'exact': True, 'size': 13, 'relocations': [],
                      'function_sha256': '3'*64, 'object_sha256': c*64} for c in ('4', '5')]}

    def test_export_is_allowlisted_reproducible_and_untrusted(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source = root/'source.cpp'; source.write_bytes(self.source)
            a, b = root/'a.zip', root/'b.zip'
            contribution.export(source, self.task, self.result, a)
            contribution.export(source, self.task, self.result, b)
            self.assertEqual(a.read_bytes(), b.read_bytes())
            with zipfile.ZipFile(a) as archive:
                self.assertEqual(len(archive.namelist()), 4)
                content = b''.join(archive.read(name) for name in archive.namelist())
                self.assertNotIn(b'PRIVATE', content)
                self.assertIn(b'requires-project-reverification', content)
                self.assertNotIn(b'Authorization', content)

    def test_mismatch_or_changed_source_cannot_export_as_pass(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); source = root/'source.cpp'; source.write_bytes(self.source)
            self.result['runs'][0]['exact'] = False
            with self.assertRaises(ValueError):
                contribution.export(source, self.task, self.result, root/'failed.zip')
            self.result['runs'][0]['exact'] = True
            source.write_bytes(self.source + b'// modified\n')
            with self.assertRaises(ValueError):
                contribution.export(source, self.task, self.result, root/'changed.zip')
            self.assertFalse((root/'failed.zip').exists())

    def test_embedded_environment_key_is_rejected(self):
        with patch.dict(os.environ, {'OPENAI_API_KEY': 'private-unit-test-key'}):
            with self.assertRaises(ValueError):
                contribution.safe_source('int X::f(){return 1;} // private-unit-test-key')

    def test_deepseek_provenance_exports_without_credentials(self):
        self.result['generation'] = 'deepseek'
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory); source = root/'source.cpp'; source.write_bytes(self.source)
            with patch.dict(os.environ, {'DEEPSEEK_API_KEY': 'deepseek-unit-test-key'}):
                contribution.export(source, self.task, self.result, root/'result.zip')
                with self.assertRaises(ValueError):
                    contribution.safe_source('int X::f(){return 1;} // deepseek-unit-test-key')
            with zipfile.ZipFile(root/'result.zip') as archive:
                content = b''.join(archive.read(name) for name in archive.namelist())
                self.assertIn(b'deepseek', content)
                self.assertNotIn(b'deepseek-unit-test-key', content)


if __name__ == '__main__':
    unittest.main()
