void __cdecl FillFromPointer(int* first, int* last, const int* valueSource)
{
    if (first != last)
    {
        do
        {
            *first = *valueSource;
            ++first;
        } while (first != last);
    }
}
