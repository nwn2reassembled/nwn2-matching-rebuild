void fill_range(unsigned long *first, unsigned long *last, unsigned long *src)
{
    while (first != last)
    {
        unsigned long tmp = *src;
        *first = tmp;
        ++first;
    }
}
