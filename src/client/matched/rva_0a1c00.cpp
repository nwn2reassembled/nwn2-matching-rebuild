void FillRange(int* first, int* last, const int* valuePtr)
{
    if (first == last)
        return;

    do
    {
        *first = *valuePtr;
        ++first;
    } while (first != last);
}
