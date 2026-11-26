unsigned char GetRange(unsigned int id)
{
    if (id >= 0x3F1 && id < 0x48A)
        return 1;
    if (id >= 0x48A && id < 0x4BE)
        return 2;
    return 0;
}
