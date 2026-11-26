struct Entry
{
    int data[15];
    unsigned char flag;
    unsigned char tail[7];
};

class EntryTable
{
    int m_prefix[10];
    unsigned short m_count;
    unsigned short m_reserved;
    Entry* m_entries;
public:
    void ClearEntryFlags();
};

void EntryTable::ClearEntryFlags()
{
    if (m_entries == 0)
        return;

    for (int i = 0; i < m_count; ++i)
        m_entries[i].flag = 0;
}
