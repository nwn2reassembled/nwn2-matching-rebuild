unsigned short GetFirstTwoCharsReversed(const char* p)
{
    union
    {
        unsigned short s;
        char b[2];
    } u;

    u.b[0] = p[1];
    u.b[1] = p[0];

    return u.s;
}
