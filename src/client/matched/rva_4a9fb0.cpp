unsigned char __cdecl IsSpecialTextColor(unsigned short color)
{
    if (color >= 0x745 && color < 0x858)
        return 1;
    if (color >= 0x858 && color < 0x8c9)
        return 2;
    return 0;
}
