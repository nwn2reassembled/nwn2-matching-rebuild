struct C
{
    unsigned int HasFlag(unsigned int mask);
    unsigned char padding[0x314];
    unsigned int flags;
};

unsigned int C::HasFlag(unsigned int mask)
{
    if (!mask)
        return 1;
    return flags & mask;
}
