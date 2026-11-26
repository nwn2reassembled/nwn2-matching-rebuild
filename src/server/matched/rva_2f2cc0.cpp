void FillFrom(void* beginArg, void* endArg, void* valueArg)
{
    unsigned long* dst = static_cast<unsigned long*>(beginArg);
    unsigned long* end = static_cast<unsigned long*>(endArg);
    unsigned long* src = static_cast<unsigned long*>(valueArg);

    if (dst != end)
    {
        do
        {
            *dst = *src;
            ++dst;
        } while (dst != end);
    }
}
