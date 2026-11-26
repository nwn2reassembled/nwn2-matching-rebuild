void fill_range(int* first, int* last, const int* value)
{
    if (first == last)
        return;
    do {
        *first = *value;
        ++first;
    } while (first != last);
}
