// NWN2RulesLib.dll RVA 0x2C7C0 (6 bytes, no fixups)
// Body: B8 9D 05 00 00 C3 -> mov eax, 0x59D; ret
// No stack args are popped and no object register is touched,
// so this is a plain callee-cleaned routine returning a constant.

int GetMaxHitPointsAtFirstLevel()
{
    return 1437;
}
