struct Entry
{
    int key;
    int reserved;
    int value;
};

struct EntryTable
{
    Entry* entries;
    int count;
};

class LookupOwner
{
    char m_reserved[0x394];
    EntryTable* m_table;

public:
    int Find(int key);
};

int LookupOwner::Find(int key)
{
    EntryTable* table = m_table;
    if (!table)
        return 1;

    for (int i = 0; i < table->count; ++i)
    {
        if (table->entries[i].key == key)
            return table->entries[i].value;
    }

    return 1;
}
