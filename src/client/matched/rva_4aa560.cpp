int __stdcall IsSpecialCase(int kind)
{
    if (kind == 1 || kind == 5 || kind == 6)
        return 1;
    return 0;
}
