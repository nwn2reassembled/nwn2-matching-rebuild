struct IntArray
{
    int* data;
    int size;
};

int __stdcall IntArraysEqual(const IntArray& a, const IntArray& b)
{
    if (a.size != b.size)
        return 0;

    for (int i = 0; i < a.size; ++i)
    {
        if (a.data[i] != b.data[i])
            return 0;
    }

    return 1;
}
