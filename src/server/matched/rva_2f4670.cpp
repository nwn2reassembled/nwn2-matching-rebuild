void* __stdcall FillN(void** dest, unsigned int count, void* const* src)
{
    unsigned int i = count;
    void** p = dest;

    while (i > 0)
    {
        *p = *src;
        --i;
        ++p;
    }

    return dest + count;
}
