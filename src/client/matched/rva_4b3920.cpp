class DataTable {
public:
    int m_count;
    int m_pad;
    unsigned short* m_entries;

    unsigned short GetEntry(int index);
};

unsigned short DataTable::GetEntry(int index)
{
    if (index < m_count)
        return m_entries[index];
    return 0xFFFFu;
}
