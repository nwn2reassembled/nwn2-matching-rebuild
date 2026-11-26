struct Init7
{
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
    int f6;

    Init7* Clear();
};

Init7* Init7::Clear()
{
    f0 = 0;
    f1 = 0;
    f2 = 0;
    f3 = 0;
    f4 = 0;
    f5 = 0;
    f6 = 0;
    return this;
}
