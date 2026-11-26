int MapCharToIndex(unsigned char c)
{
    if (c < 10)
        return (int)(c - 11) / 2;
    else
        return (int)(c - 10) / 2;
}
