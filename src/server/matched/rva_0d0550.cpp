int* __stdcall copy_n(int* dst, unsigned int count, int* src)
{
    unsigned int remaining = count;
    int* p = dst;

    while (remaining > 0)
    {
        *p = *src;
        --remaining;
        ++p;
    }

    return dst + count;
}
