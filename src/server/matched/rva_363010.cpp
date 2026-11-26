struct SessionRecord
{
    unsigned char pad0[0x318];
    int key;
    unsigned char pad1[0x10];
    int state;
    unsigned char pad2[8];
};

class SessionTable
{
public:
    SessionRecord *Find(int key);

    int m_count;
    SessionRecord *m_items;
};

SessionRecord *SessionTable::Find(int key)
{
    int i;

    for (i = 0; i < m_count; i++)
    {
        if (m_items[i].key == key && m_items != 0 && i >= 0 && i < m_count && m_items[i].state == 1)
            return &m_items[i];
    }
    return 0;
}
