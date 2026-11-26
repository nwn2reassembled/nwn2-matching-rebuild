void FillRange(int* first, int* last, const int* value)
{
    if (first == last)
        return;

    while (first != last)
    {
        *first = *value;
        first = first + 1;
    }
}
