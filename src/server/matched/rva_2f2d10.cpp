void FillDwords(void **dest, void **destEnd, void **src)
{
    if (dest != destEnd)
    {
        do
        {
            *dest = *src;
            dest++;
        } while (dest != destEnd);
    }
}
