// NWN2RulesLib.dll RVA 0x2aeb0
// Plain near return (RET, no imm16) => cdecl; returns constant 0x3FE (1022).
unsigned int GetSomeRulesConstant()
{
    return 1022u;
}
