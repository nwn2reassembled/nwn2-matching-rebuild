// Target: NWN2RulesLib.dll RVA 0x29460 (6 bytes, no fixups)

// Body is exactly:
//   mov eax, 0x247
//   ret
// i.e. an argument-less function returning the constant 583 (0x247).

unsigned int GetSomeRulesValue(void)
{
    return 583u; // 0x247
}
