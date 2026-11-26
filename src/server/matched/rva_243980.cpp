struct C {
    unsigned char pad0[0x2344];
    int f2344;
    unsigned char pad1[8];
    int f2350;
    int f2354;
    int f2358;
    unsigned char pad2[4];
    int f2360;
    int f2364;
    int check(int a, int b);
};

int C::check(int a, int b)
{
    if (f2360 == 1 && f2364 != a)
        return 0;

    if (f2344 != 1)
        return 1;

    int t = f2354 - f2358 - f2350 + 1000;
    return t >= b;
}
