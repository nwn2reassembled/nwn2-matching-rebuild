struct C
{
    unsigned char pad[0xdd];
    unsigned char table[7];
    unsigned char Get(unsigned int index) const;
};

unsigned char C::Get(unsigned int index) const
{
    if (index <= 6)
        return table[index];
    return 0;
}
