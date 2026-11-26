void FillWideRange(unsigned short* first, unsigned short* last, const unsigned short* valuePtr)
{
    if (first != last)
    {
        for (; first != last; ++first)
        {
            *first = *valuePtr;
        }
    }
}
