int __cdecl ParseCode(unsigned char code)
{
    if (code < 10)
        return (int)(code - 11) / 2;
    return (int)(code - 10) / 2;
}
