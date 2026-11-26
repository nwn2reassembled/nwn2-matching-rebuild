void FillFromWordCdecl(unsigned long *dest, unsigned long *end, unsigned long *src)
{
    if (dest != end)
    {
        do
        {
            *dest = *src;
            ++dest;
        } while (dest != end);
    }
}
