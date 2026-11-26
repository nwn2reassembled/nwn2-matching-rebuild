struct C
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;
    int m6;
    char m7;
    char m8;
    int m9;

    C* Reset();
};

C* C::Reset()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
    m6 = 0;
    m7 = 0;
    m8 = 0;
    m9 = 0;
    return this;
}
