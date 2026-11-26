int __stdcall IsSpecialWord(unsigned short code)
{
    if (code == 0xd1 || code == 0xd2)
        return 1;
    return 0;
}
