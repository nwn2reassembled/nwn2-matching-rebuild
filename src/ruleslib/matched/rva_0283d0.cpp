// NWN2RulesLib.dll, RVA 0x283d0

struct RulesAreaInfo {
    char pad[0xd8];
};

unsigned int GetRulesAreaInfoSize()
{
    return sizeof(RulesAreaInfo);
}
