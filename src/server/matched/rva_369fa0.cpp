unsigned char ClassTier(unsigned char id)
{
    if (id >= 0x35 && id < 0x3B)
        return 1;
    if (id >= 0x3B && id < 0xFE)
        return 2;
    return 0;
}
