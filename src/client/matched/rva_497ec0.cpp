class ItemTable {
    char m_pad[0x2F0];           // +0x000
    unsigned short* m_entries;   // +0x2F0
    unsigned char   m_count;     // +0x2F4

public:
    unsigned short GetEntry(unsigned char index) /* thiscall */;
};

unsigned short __thiscall ItemTable::GetEntry(unsigned char index)
{
    if (index >= m_count)
        return 0xFFFF;
    return m_entries[index];
}
