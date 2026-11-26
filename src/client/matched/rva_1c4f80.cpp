struct C
{
    unsigned char pad0[0x100c];
    int m_mode;
    unsigned char pad1[0x17d0 - 0x1010];
    unsigned char m_table[1];
    unsigned char pad2[0x1fc4 - 0x17d1];
    unsigned char *m_extra;

    int Get(int index);
};

int C::Get(int index)
{
    if (m_mode != 0)
        return m_table[index];
    return m_extra[index + 4];
}
