struct Stats {
    unsigned char pad00[0x14];
    int field14;
    unsigned char pad18[0x1C];
    int field34;
    unsigned char pad38[0xE];
    short field46;
    unsigned char pad48[0x8];
    short field50;
    unsigned char pad52[0x9];
    unsigned char field5B;
    unsigned char pad5C[4];
};

Stats *UpdateStats(Stats *s)
{
    s->field14 = s->field46;
    s->field34 = (int)((char *)s + s->field46 * s->field5B + s->field50 + 0x5C);
    return s;
}
