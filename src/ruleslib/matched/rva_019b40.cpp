unsigned char NWN2RulesLib_IsSomething(unsigned char c)
{
    if (c >= 0x35 && c < 0x3b)
        return 1;
    if (c >= 0x3b && c < 0xfe)
        return 2;
    return 0;
}
