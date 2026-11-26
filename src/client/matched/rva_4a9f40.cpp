unsigned __stdcall HighestBitIndex(unsigned x)
{
    unsigned n = 0;
    unsigned v = x >> 1;
    while (v != 0)
    {
        n = n + 1;
        v = v >> 1;
    }
    return n;
}
