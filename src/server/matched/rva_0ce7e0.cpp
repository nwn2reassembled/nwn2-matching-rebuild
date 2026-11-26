void fill_ints(int* first, int* last, const int* value)
{
    for (; first != last; ++first)
        *first = *value;
}
