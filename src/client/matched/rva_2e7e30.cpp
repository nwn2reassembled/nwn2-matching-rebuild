struct Entry
{
    int key;
    int value;
    int reserved;
};

struct EntryTable
{
    Entry* entries;
    int count;
};

class Object
{
public:
    int FindValue(int key);

private:
    unsigned char m_reserved[0x394];
    EntryTable* m_table;
};

int Object::FindValue(int key)
{
    EntryTable* table = m_table;
    if (table == 0)
        return 1;

    for (int i = 0; i < table->count; ++i)
    {
        if (table->entries[i].key == key)
            return table->entries[i].value;
    }

    return 1;
}
