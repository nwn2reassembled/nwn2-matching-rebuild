void fill_qword(long long* first, long long* last, const long long* value)
{
    while (first != last)
    {
        *first = *value;
        ++first;
    }
}
