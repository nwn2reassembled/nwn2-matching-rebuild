struct X
{
    int a[20];
};

void __stdcall CopyData(X* dst, const X* src)
{
    if (dst != 0)
    {
        *dst = *src;
    }
}
