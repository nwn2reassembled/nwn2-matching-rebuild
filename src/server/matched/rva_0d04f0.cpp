unsigned long* __stdcall FillDwords(unsigned long* dest, unsigned int count, unsigned long* src)
{
    unsigned int remaining = count;
    unsigned long* p = dest;

    if (count > 0)
    {
        do
        {
            *p = *src;
            remaining--;
            p++;
        } while (remaining > 0);
    }

    return dest + count;
}
