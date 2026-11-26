struct U
{
    unsigned long v;
};

void FillRange(U* first, U* end, const U* src)
{
    if (first != end)
    {
        do
        {
            first->v = src->v;
            ++first;
        } while (first != end);
    }
}
