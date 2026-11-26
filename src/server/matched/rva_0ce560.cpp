void copy_same(int* first, int* last, const int* value)
{
    while (first != last)
    {
        *first = *value;
        ++first;
    }
}
