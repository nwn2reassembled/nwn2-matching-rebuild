struct Entry
{
    int id;
    int value;
};

struct Object
{
    int reserved[108];
    Entry* entries;
    int capacity;
    int entryCount;
    Entry* Find(int id);
};

Entry* Object::Find(int id)
{
    int n = entryCount;
    for (int i = 0; i < n; ++i)
    {
        if (entries[i].id == id)
            return &entries[i];
    }
    return 0;
}
