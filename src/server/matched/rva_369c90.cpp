struct Holder
{
    unsigned char padding[0x1a0];
    unsigned char values[1];

    int Get(int a, int b) const;
};

int Holder::Get(int a, int b) const
{
    return values[a + b * 7];
}
