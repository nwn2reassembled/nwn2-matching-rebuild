// NWN2RulesLib.dll RVA 0x2fa00, 6 bytes
// mov eax, 0x8c7; ret  -> caller cleans stack -> __cdecl, no arguments.
// Returns the constant 2247 (0x8C7), plausibly a rules/engine build or
// rules-version constant used by the rules library.

unsigned int GetRulesVersion(void)
{
    return 0x8C7u; // 2247
}
