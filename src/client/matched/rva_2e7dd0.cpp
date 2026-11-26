struct Entry
{
    int key;
    int unused;
    int value;
};

struct EntryList
{
    Entry* entries;
    int count;
};

class C
{
public:
    void SetValue(int key, int value);

    char m_reserved[0x394];
    EntryList* m_pList;
    int m_unused;
    int m_changed;
};

void C::SetValue(int key, int value)
{
    if (m_pList != 0)
    {
        for (int i = 0; i < m_pList->count; ++i)
        {
            if (m_pList->entries[i].key == key)
            {
                m_pList->entries[i].value = value;
                m_changed = 1;
            }
        }
    }
}
