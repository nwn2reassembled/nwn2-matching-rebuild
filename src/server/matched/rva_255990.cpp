struct ServerState
{
    unsigned long GetTableEntry(unsigned long index);

    unsigned char m_pad[0x88];
    unsigned long m_table[4];
};

unsigned long ServerState::GetTableEntry(unsigned long index)
{
    if (index <= 3)
        return m_table[index];
    return 0;
}
