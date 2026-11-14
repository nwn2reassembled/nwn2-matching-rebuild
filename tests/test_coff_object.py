from pathlib import Path
import struct
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from coff_object import CoffObject


def fixture(long_name=False, relocation=None, aux_size=None):
    """Synthetic conventional COFF object. No original game instructions."""
    name = 'synthetic_function_long_name' if long_name else 'leaf'
    code = b'\x90\x90\x90\xc3'
    raw_offset = 60
    relocation_data = struct.pack('<IIH', relocation[0], 0, relocation[1]) if relocation else b''
    symbol_offset = raw_offset + len(code) + len(relocation_data)
    aux = struct.pack('<IIIIH', 0, aux_size, 0, 0, 0) if aux_size is not None else b''
    symbol_name = struct.pack('<II', 0, 4) if long_name else b'leaf\0\0\0\0'
    symbol = struct.pack('<8sIhHBB', symbol_name, 0, 1, 0x20, 2, int(aux_size is not None))
    strings = name.encode() + b'\0' if long_name else b''
    header = struct.pack('<HHIIIHH', 0x14c, 1, 0, symbol_offset, 1 + int(aux_size is not None), 0, 0)
    section = struct.pack('<8sIIIIIIHHI', b'.text\0\0\0', 0, 0, len(code), raw_offset,
                          raw_offset + len(code) if relocation else 0, 0,
                          1 if relocation else 0, 0, 0x60000020)
    return bytearray(header + section + code + relocation_data + symbol + aux + struct.pack('<I', len(strings) + 4) + strings), name


class CoffTests(unittest.TestCase):
    def test_explicit_symbol_extraction(self):
        data, name = fixture()
        code, metadata = CoffObject(data).extract(name, 4, 'synthetic full function')
        self.assertEqual(code, b'\x90\x90\x90\xc3')
        self.assertEqual(metadata['object_relocations'], [])
        self.assertEqual(metadata['file_offset'], 60)

    def test_long_symbol_name(self):
        data, name = fixture(long_name=True)
        self.assertEqual(CoffObject(data).symbols[0]['name'], name)

    def test_aux_size_must_agree(self):
        data, name = fixture(aux_size=4)
        obj = CoffObject(data)
        obj.extract(name, 4, 'synthetic')
        with self.assertRaises(ValueError):
            obj.extract(name, 3, 'wrong size')

    def test_explicit_boundary_required(self):
        data, name = fixture()
        for size, evidence in [(4, ''), (0, 'x'), (5, 'too long')]:
            with self.assertRaises(ValueError):
                CoffObject(data).extract(name, size, evidence)

    def test_overlapping_and_unknown_fixups_rejected(self):
        for relocation in [(0, 6), (1, 20), (0, 0x7777)]:
            data, name = fixture(relocation=relocation)
            with self.assertRaises(ValueError):
                CoffObject(data).extract(name, 4, 'synthetic')

    def test_fixup_straddles_function_start(self):
        data, name = fixture(relocation=(0, 6))
        obj = CoffObject(data)
        obj.symbols[0]['value'] = 2
        with self.assertRaises(ValueError):
            obj.extract(name, 2, 'synthetic range')

    def test_absolute_padding_not_a_fixup(self):
        data, name = fixture(relocation=(0, 0))
        self.assertEqual(CoffObject(data).extract(name, 4, 'synthetic')[1]['object_relocations'], [])

    def test_wrong_machine_and_pe_rejected(self):
        data, _ = fixture()
        struct.pack_into('<H', data, 0, 0x8664)
        for invalid in [data, b'MZ' + bytes(200), b'!<arch>\n' + bytes(100), bytes(20)]:
            with self.assertRaises(ValueError):
                CoffObject(invalid)

    def test_truncations_and_bad_string_table(self):
        data, _ = fixture(long_name=True)
        for end in [0, 19, 59, len(data) - 1]:
            with self.assertRaises(ValueError):
                CoffObject(data[:end])
        symbol_offset = struct.unpack_from('<I', data, 8)[0]
        struct.pack_into('<I', data, symbol_offset + 4, 0xffffffff)
        with self.assertRaises(ValueError):
            CoffObject(data)

    def test_non_function_and_non_executable_rejected(self):
        data, name = fixture()
        obj = CoffObject(data)
        obj.symbols[0]['type'] = 0
        with self.assertRaises(ValueError):
            obj.extract(name, 4, 'synthetic')
        obj.symbols[0]['type'] = 0x20
        obj.sections[0]['executable'] = False
        with self.assertRaises(ValueError):
            obj.extract(name, 4, 'synthetic')

    def test_duplicate_symbol_rejected(self):
        data, name = fixture()
        obj = CoffObject(data)
        obj.symbols.append(dict(obj.symbols[0]))
        with self.assertRaises(ValueError):
            obj.extract(name, 4, 'synthetic')


if __name__ == '__main__':
    unittest.main()
