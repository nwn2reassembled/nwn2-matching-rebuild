struct Inventory {
    unsigned char m_unknown0[0x15b];
    unsigned char m_count;
    unsigned char m_unknown1[0x14];
    char* m_entries;

    void* GetEntry(unsigned short index);
};

void* Inventory::GetEntry(unsigned short index)
{
    if (index < (unsigned short)m_count)
        return m_entries + index * 0x9c;
    return 0;
}
