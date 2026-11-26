unsigned int __stdcall BitLength(unsigned int value)
{
    unsigned int n = 0;
    value >>= 1;
    while (value != 0)
    {
        ++n;
        value >>= 1;
    }
    return n;
}
