struct C
{
    char Get(unsigned char index);
    char data[0x700];
};

char C::Get(unsigned char index)
{
    unsigned char n = index - 1;
    if (n <= 0x27)
        return data[0x585 + index];
    return 0;
}
