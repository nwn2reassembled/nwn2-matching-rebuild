struct Legacy {
    char pad[0xf28];
    unsigned int field;
    int test(unsigned mask) const;
};

int Legacy::test(unsigned mask) const
{
    return (field & mask) != 0 ? 1 : 0;
}

