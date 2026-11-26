struct ByteBits
{
    unsigned char data[0x100b1];
    bool Test(unsigned char mask) const;
};

bool ByteBits::Test(unsigned char mask) const
{
    return (data[0x100b0] & mask) > 0;
}
