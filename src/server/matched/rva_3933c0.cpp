int __stdcall ReleaseIfNotNull(int* p)
{
    if (p == 0)
        return 0;
    *p = 0;
    return 1;
}
