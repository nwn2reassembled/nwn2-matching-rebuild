int GetStoredValue()
{
    int *p = *(int **)0x86cc04;
    return p ? p[2] : 0;
}
