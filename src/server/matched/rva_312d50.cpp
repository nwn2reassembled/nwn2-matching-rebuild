void FillRange(int* first, int* last, int* value)
{
    while (first != last)
    {
        *first = *value;
        ++first;
    }
}
