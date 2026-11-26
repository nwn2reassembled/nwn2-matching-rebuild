struct Entry {
    int field_0;
    int state;
    int field_8;
};

struct EntryList {
    Entry* entries;   // +0x0
    int    count;     // +0x4
};

class Container {
public:
    void MarkAllEntriesActive();

private:
    unsigned char m_pad[0x5d8]; // fields up to +0x5d7 (contents unknown)
    EntryList*    m_list;       // +0x5d8
};

void Container::MarkAllEntriesActive()
{
    for (int i = 0; i < m_list->count; i++) {
        m_list->entries[i].state = 1;
    }
}
