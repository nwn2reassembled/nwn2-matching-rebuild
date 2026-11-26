int* __stdcall Fill(int* dest, unsigned int count, int* src)
{
    unsigned int n = count;
    int* p = dest;
    if (count > 0)
    {
        do
        {
            *p = *src;
            n = n - 1;
            p = p + 1;
        }
        while (n > 0);
    }
    return dest + count;
}
