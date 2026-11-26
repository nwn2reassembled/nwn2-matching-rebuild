unsigned char __cdecl GetLevelTier(unsigned int n)
{
    if (n >= 0x3F1 && n < 0x48A)
        return 1;
    if (n >= 0x48A && n < 0x4BE)
        return 2;
    return 0;
}
