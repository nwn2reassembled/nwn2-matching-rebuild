struct TableHolder {
    char m_pad[0x63C];
    unsigned char m_table[40];

    unsigned char GetEntry(unsigned char row, unsigned char col);
};

unsigned char TableHolder::GetEntry(unsigned char row, unsigned char col)
{
    if (row < 4 && col < 10)
        return m_table[row * 10 + col];
    return 0;
}
