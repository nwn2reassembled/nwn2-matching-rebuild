void Fill(unsigned long* first, const unsigned long* last, unsigned long* src)
{
    while (first != last)
    {
        *first = *src;
        ++first;
    }
}
