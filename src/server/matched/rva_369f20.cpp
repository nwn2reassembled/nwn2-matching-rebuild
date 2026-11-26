unsigned char __cdecl classify_wchar(unsigned short code)
{
    if (code >= 0x745 && code < 0x858)
        return 1;

    if (code >= 0x858 && code < 0x8c9)
        return 2;

    return 0;
}
