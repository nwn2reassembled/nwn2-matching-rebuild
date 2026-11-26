struct Something
{
    unsigned char data[0x14];
    unsigned char limit;
    unsigned char get(unsigned char row, unsigned char col);
};

unsigned char Something::get(unsigned char row, unsigned char col)
{
    if (row >= limit)
        return 0;
    if (col >= 10)
        return 0;
    return data[row * 0x124 + (col + 0x23) * 12];
}
