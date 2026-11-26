unsigned int* __stdcall FillDwords(unsigned int* dest, unsigned int count, unsigned int* valueSrc)
{
    unsigned int n = count;
    unsigned int* p = dest;

    if (n > 0)
    {
        do
        {
            *p = *valueSrc;
            n = n - 1;
            p = p + 1;
        } while (n > 0);
    }

    return dest + count;
}
