unsigned int __stdcall TickDelta60(unsigned int a, unsigned int b)
{
    if (a >= b)
        return a - b;
    return a + 60u - b;
}
