void FillRange(int* first, int* last, const int* valueSource)
{
    if (first == last)
        return;

    while (first != last)
    {
        *first = *valueSource;
        ++first;
    }
}
