struct Buffer {
    unsigned char bytes[32];
    unsigned char FirstZero() const;
};

unsigned char Buffer::FirstZero() const
{
    unsigned char i = 0;
    while (i < 32 && bytes[i] != 0)
        ++i;
    return i;
}
