struct Mgr {
    char pad[0x53d];
    unsigned char table[4][0x10c];

    unsigned char GetFlag(unsigned char idx);
};

unsigned char Mgr::GetFlag(unsigned char idx)
{
    if (idx >= 4)
        return 0;
    return table[idx][0];
}
