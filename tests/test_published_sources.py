"""Public snapshot integrity, not fresh compiler verification."""
import hashlib
import json
from pathlib import Path
import unittest

ROOT = Path(__file__).resolve().parents[1]


class PublishedSourcesTest(unittest.TestCase):
    def test_snapshot_integrity(self):
        index = json.loads((ROOT / 'src/matched/index.json').read_text())
        functions = index['functions']
        self.assertGreaterEqual(len(functions), 522)
        self.assertEqual(len({f['source'] for f in functions}), index['published_source_file_count'])
        self.assertEqual(sum(f['size'] for f in functions), index['matched_instruction_bytes'])
        self.assertEqual(len({(f['binary'], f['rva']) for f in functions}), len(functions))
        self.assertEqual(index['verified_function_count'], len(functions))
        progress = json.loads((ROOT / 'docs/research-progress.json').read_text())
        self.assertEqual(index['known_corpus_items'], progress['known_corpus_items'])
        self.assertGreaterEqual(index['known_corpus_items'], 53853)
        ends = {}
        for f in functions:
            self.assertGreaterEqual(int(f['rva'], 0), ends.get(f['binary'], 0))
            ends[f['binary']] = int(f['rva'], 0) + f['size']
            self.assertEqual(hashlib.sha256((ROOT / f['source']).read_bytes()).hexdigest(), f['source_sha256'])
            receipt = json.loads((ROOT / f['verification']).read_text())
            for key in ('source', 'source_sha256', 'rva', 'size', 'symbol'):
                self.assertEqual(receipt[key], f[key])
            comparison = receipt['reference_comparison']
            self.assertTrue(comparison['exact'])
            self.assertEqual(comparison['reference_sha256'], comparison['candidate_sha256'])
            self.assertEqual(comparison['reference_size'], f['size'])
            self.assertEqual(comparison['candidate_size'], f['size'])
            self.assertEqual(receipt['normalization'], 'none')
            self.assertFalse(receipt['publication_source_edited'])
            self.assertFalse(receipt['whole_file_identity'])

    def test_per_binary_indexes_reconcile(self):
        combined = json.loads((ROOT / 'src/matched/index.json').read_text())
        functions = []
        for lane in ('ruleslib', 'server', 'client'):
            index = json.loads((ROOT / f'src/{lane}/matched/index.json').read_text())
            self.assertEqual(index['verified_function_count'], len(index['functions']))
            self.assertEqual(index['matched_instruction_bytes'], sum(f['size'] for f in index['functions']))
            functions.extend(index['functions'])
        self.assertEqual(sorted(functions, key=lambda f: (f['binary'], int(f['rva'], 0))), combined['functions'])

    def test_readme_counter_and_process_diagram(self):
        readme = (ROOT / 'README.md').read_text()
        index = json.loads((ROOT / 'src/matched/index.json').read_text())
        count = index['verified_function_count']
        self.assertIn(f"## **{count:,} / {index['known_corpus_items']:,}", readme)
        self.assertIn('```mermaid\nflowchart TD', readme)
        self.assertIn('Whole-file identity: 0 / 6', readme)
        self.assertIn('once every 24 hours', readme)
