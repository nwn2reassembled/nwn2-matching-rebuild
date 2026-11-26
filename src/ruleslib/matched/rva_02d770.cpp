// NWN2RulesLib.dll RVA 0x2D770 (6 bytes)
// mov eax, 0x69B; ret  => caller-cleaned convention (no imm16 in ret)
// Stack-passed object (sret-style / by-value struct) or plain value return;
// cdecl is the safe ABI reading.

unsigned int GetMaxLevel()
{
    return 0x69B; // 1691
}
