struct Entry
{
    int values[5];
};

struct Store
{
    Entry* Get(int index);

    char reserved[0x16bc];
    int count;
    Entry* entries;
};

Entry* Store::Get(int index)
{
    if (index < 0 || index >= count)
        return 0;
    return &entries[index];
}
