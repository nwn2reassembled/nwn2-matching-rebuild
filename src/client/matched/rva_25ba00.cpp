struct C
{
    char pad0[0x2344];
    int f2344;
    char pad1[8];
    int f2350;
    int f2354;
    int f2358;
    char pad2[4];
    int f2360;
    int f2364;
    int f2368;
    int Func(int a, int b, int c);
};

int C::Func(int a, int b, int c)
{
    if (f2360 == 1 && f2364 != a && f2350 + c < f2350 + f2368)
        return 0;
    if (f2344 != 1)
        return 1;
    return (f2354 - f2358 - f2350 - c + 1000) >= b;
}
