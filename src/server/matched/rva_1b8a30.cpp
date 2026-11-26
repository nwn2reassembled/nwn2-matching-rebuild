struct Entry
{
    int key;
    int value;
};

class EntryTable
{
public:
    Entry* Find(int key);

private:
    char reserved[0x1b0];
    Entry* entries;
    int unused;
    int count;
};

Entry* EntryTable::Find(int key)
{
    for (int i = 0; i < count; ++i)
    {
        if (entries[i].key == key)
            return &entries[i];
    }
    return 0;
}
