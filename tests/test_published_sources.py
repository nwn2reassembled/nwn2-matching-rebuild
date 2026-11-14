"""Public snapshot integrity, not fresh compiler verification."""
import hashlib
import json
from pathlib import Path
import unittest

ROOT = Path(__file__).resolve().parents[1]


class PublishedSourcesTest(unittest.TestCase):
    def test_snapshot_integrity(self):
        index = json.loads((ROOT / 'src/ruleslib/matched/index.json').read_text())
        functions = index['functions']
        self.assertEqual(len(functions), 357)
        self.assertEqual(len({f['source'] for f in functions}), 355)
        self.assertEqual(sum(f['size'] for f in functions), 8543)
        self.assertEqual(len({f['rva'] for f in functions}), 357)
        end = 0
        for f in functions:
            self.assertGreaterEqual(int(f['rva'], 0), end)
            end = int(f['rva'], 0) + f['size']
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
