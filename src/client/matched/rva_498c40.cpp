struct C
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    C* Reset();
};

C* C::Reset()
{
    e = 0;
    f = 0;
    g = 0;
    h = 0;
    i = 0;
    j = 0;
    a = 0;
    b = 0;
    d = 0;
    c = 0;
    return this;
}
