void CopyDWordRange(unsigned long* dst, unsigned long* dstEnd, unsigned long* src)
{
    if (dst == dstEnd)
        return;

    do
    {
        *dst = *src;
        dst = dst + 1;
    } while (dst != dstEnd);
}
