bool __cdecl CheckRuleValue(unsigned short value)
{
    if (value >= 0x65 && value < 0x64)
        return true;
    return false;
}
