void FillRangeFromPointer(int* first, int* end, int* src)
{
    int* p = first;
    if (p != end)
    {
        do
        {
            *p = *src;
            ++p;
        } while (p != end);
    }
}
