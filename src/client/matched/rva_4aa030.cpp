char __cdecl classify_token_byte(unsigned char b)
{
    if (b >= 0x35 && b < 0x3b)
        return 1;
    if (b >= 0x3b && b < 0xfe)
        return 2;
    return 0;
}
