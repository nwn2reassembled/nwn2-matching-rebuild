struct CContext
{
    char pad[0xA4];
    unsigned char state;

    int Allows(unsigned short id);
};

int CContext::Allows(unsigned short id)
{
    if (state == 5)
    {
        if (id == 0 || id == 0x34 || id == 1 || id == 5 || id == 7 ||
            id == 0x61 || id == 0x62 || id == 0x24 || id == 0xF || id == 0x10 ||
            id == 0xB9 || id == 0xB8 || id == 0xBA || id == 0xBC || id == 0xC4 ||
            id == 0xBB || id == 0x2F || id == 0x39 || id == 0x3A || id == 0xFA ||
            id == 0xFB || id == 0xFC || id == 0xFD || id == 0x105 || id == 0x3B ||
            id == 0x3C || id == 0x3E || id == 0x5E || id == 0x3F || id == 0x5F ||
            id == 0x5D || id == 2 || id == 3 || id == 4 || id == 0x50 ||
            id == 0x51 || id == 0x52 || id == 0x53 || id == 0x6E || id == 0x75 ||
            id == 0x7A || id == 0x7B || id == 0x7C || id == 0x7E || id == 0x7F ||
            id == 0x81 || id == 0x82 || id == 0x84 || id == 0x85 || id == 0x98 ||
            id == 0x99 || id == 0x9A || id == 0x9B || id == 0x9C || id == 0x9E ||
            id == 0xA0 || id == 0xA1 || id == 0xA2 || id == 0xA3 || id == 0xA4 ||
            id == 0xA5 || id == 0xC5 || id == 0xC6 || id == 0xA9 || id == 0xC2 ||
            id == 0xC3 || id == 0x1E || id == 0x26 || id == 0x27 || id == 0x28 ||
            id == 0x29)
            return 1;
    }
    else if (state == 10)
    {
        if (id == 0x32 || id == 0x33 || id == 0x16 || id == 0x48 || id == 0)
            return 1;
    }
    else if (state == 9)
    {
        if (id == 0x48 || id == 0x49 || id == 0x4A || id == 0x4B || id == 0x4C || id == 0)
            return 1;
    }
    return 0;
}
