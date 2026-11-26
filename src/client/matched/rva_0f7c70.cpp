struct CHolder
{
    unsigned char padding[0x1d8];
    unsigned int values[0x27];

    unsigned int GetValue(unsigned int index);
};

unsigned int CHolder::GetValue(unsigned int index)
{
    if (index <= 0x26)
        return values[index];
    return 0;
}
