import json
from pathlib import Path
import struct
import sys
import tempfile
from types import SimpleNamespace as NS
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from matching import (compare_bytes, compare_regions, extract_function, offset_to_rva,
                      relocation_overlaps, rva_to_offset, sha256, va_to_offset,
                      verify_file)


def synthetic_pe():
    """Entirely synthetic PE32 fixture: no proprietary input needed by tests."""
    data = bytearray(0x400)
    data[:2] = b'MZ'
    struct.pack_into('<I', data, 0x3c, 0x80)
    data[0x80:0x84] = b'PE\0\0'
    struct.pack_into('<HHIIIHH', data, 0x84, 0x14c, 1, 0, 0, 0, 224, 0x2102)
    o = 0x98
    struct.pack_into('<H', data, o, 0x10b)
    for offset, value in [(16, 0x1000), (20, 0x1000), (28, 0x10000000),
                          (32, 0x1000), (36, 0x200), (56, 0x2000), (60, 0x200), (92, 16)]:
        struct.pack_into('<I', data, o + offset, value)
    struct.pack_into('<H', data, o + 68, 3)
    struct.pack_into('<8sIIIIIIHHI', data, o + 224, b'.text\0\0\0',
                     0x300, 0x1000, 0x200, 0x200, 0, 0, 0, 0, 0x60000020)
    data[0x200:0x204] = b'\x90\x90\x90\xc3'
    return bytes(data)


class ComparisonTests(unittest.TestCase):
    def test_exact(self):
        self.assertTrue(compare_bytes(b'abc', b'abc')['exact'])

    def test_each_one_byte_mutation_fails(self):
        reference = bytes(range(256))
        for i in range(len(reference)):
            changed = bytearray(reference)
            changed[i] ^= 1
            result = compare_bytes(reference, changed)
            self.assertFalse(result['exact'])
            self.assertEqual(result['first_mismatch'], i)
            self.assertEqual(result['different_bytes_including_missing'], 1)

    def test_truncation_and_append(self):
        for candidate in (b'ab', b'abcd'):
            self.assertFalse(compare_bytes(b'abc', candidate)['exact'])

    def test_empty(self):
        self.assertTrue(compare_bytes(b'', b'')['exact'])
        self.assertEqual(compare_bytes(b'', b'a')['first_mismatch'], 0)

    def test_wrong_reference(self):
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'ref'
            path.write_bytes(b'wrong')
            with self.assertRaises(ValueError):
                verify_file(path, {'size': 5, 'sha256': sha256(b'right')})

    def test_region_is_not_artifact(self):
        result = compare_regions(b'XabcY', b'ZabcW', 1, 1, 3)
        self.assertTrue(result['comparison']['exact'])
        self.assertFalse(result['exact_artifact_claim'])
        self.assertEqual(result['excluded_reference_ranges'], [[0, 1], [4, 5]])
        self.assertFalse(compare_bytes(b'XabcY', b'ZabcW')['exact'])

    def test_invalid_region(self):
        for offset, size in [(-1, 1), (0, 0), (2, 2)]:
            with self.assertRaises(ValueError):
                compare_regions(b'abc', b'abc', offset, 0, size)


class PETests(unittest.TestCase):
    def setUp(self):
        import pefile
        self.pe = pefile.PE(data=synthetic_pe())

    def test_addresses(self):
        self.assertEqual(rva_to_offset(self.pe, 0x1000, 4), 0x200)
        self.assertEqual(offset_to_rva(self.pe, 0x203), 0x1003)
        self.assertEqual(va_to_offset(self.pe, 0x10001000), 0x200)
        self.assertEqual(rva_to_offset(self.pe, 0x80), 0x80)

    def test_invalid_ranges(self):
        for rva, size in [(-1, 1), (0, 0), (0x1200, 1), (0x11ff, 2), (0x5000, 1)]:
            with self.assertRaises(ValueError):
                rva_to_offset(self.pe, rva, size)
        for offset in [-1, 0x400]:
            with self.assertRaises(ValueError):
                offset_to_rva(self.pe, offset)

    def test_overlay_unmapped(self):
        self.pe.__data__ += b'overlay'
        with self.assertRaises(ValueError):
            offset_to_rva(self.pe, 0x400)

    def test_ambiguous_mapping(self):
        self.pe.sections.append(self.pe.sections[0])
        with self.assertRaises(ValueError):
            rva_to_offset(self.pe, 0x1000)

    def test_truncated_section(self):
        self.pe.__data__ = self.pe.__data__[:0x201]
        with self.assertRaises(ValueError):
            rva_to_offset(self.pe, 0x1000, 4)

    def test_relocation_straddles_range_start(self):
        self.pe.DIRECTORY_ENTRY_BASERELOC = [NS(entries=[NS(rva=0x1000, type=3), NS(rva=0x1001, type=0)])]
        self.assertEqual(len(relocation_overlaps(self.pe, 0x1002, 1)), 1)
        self.assertEqual(relocation_overlaps(self.pe, 0x1004, 1), [])
        # A fixup difference is never normalized away by the comparator.
        self.assertFalse(compare_bytes(b'\x00\x10', b'\x00\x20')['exact'])

    def test_extraction_requires_pin_and_evidence(self):
        data = synthetic_pe()
        pin = {'size': len(data), 'sha256': sha256(data)}
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / 'synthetic'
            path.write_bytes(data)
            function, metadata = extract_function(path, pin, 0x1000, 4, 'synthetic fixture boundary')
            self.assertEqual(function, b'\x90\x90\x90\xc3')
            self.assertEqual(metadata['file_offset'], 0x200)
            with self.assertRaises(ValueError):
                extract_function(path, pin, 0x1000, 4, '')
            path.write_bytes(data[:-1])
            with self.assertRaises(ValueError):
                extract_function(path, pin, 0x1000, 4, 'boundary')


if __name__ == '__main__':
    unittest.main()
