struct C {
    unsigned char pad0[0x50];
    unsigned char m50;
    unsigned char m51;
    unsigned char m52;
    unsigned char m53;
    unsigned char m54;
    unsigned char m55;
    unsigned char m56;
    unsigned char m57;
    unsigned char m58;
    unsigned char pad1[0x2CB];
    unsigned short m324;
    int Check() const;
};

int C::Check() const
{
    if (m58 >= 10)
        return 1;
    if (m324 != 0)
        return 0;
    if (m50 < 10)
        return 1;
    if (m51 < 10)
        return 1;
    if (m52 < 10)
        return 1;
    if (m53 < 10)
        return 1;
    if (m54 < 10)
        return 1;
    if (m55 < 10)
        return 1;
    if (m56 < 10)
        return 1;
    return m57 < 10;
}
