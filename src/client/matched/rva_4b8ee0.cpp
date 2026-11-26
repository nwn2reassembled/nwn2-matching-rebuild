unsigned int __stdcall WrapDelta60(unsigned int a, unsigned int b)
{
    if (a >= b)
        return a - b;
    return a - b + 60;
}
