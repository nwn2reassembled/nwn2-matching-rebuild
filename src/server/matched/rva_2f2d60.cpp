void FillFrom(unsigned int* first, unsigned int* end, const unsigned int* src)
{
    if (first == end)
        return;

    const unsigned int* p = src;
    while (first != end)
    {
        *first = *p;
        ++first;
    }
}
