struct Entry
{
    int field0;
    int field4;
};

struct Container
{
    unsigned short* keys;
    int capacity;
    int count;
    Entry* entries;

    Entry* Find(unsigned short key);
};

Entry* Container::Find(unsigned short key)
{
    int i = 0;
    while (i < count)
    {
        if (keys[i] == key)
            return &entries[i];
        ++i;
    }
    return *(Entry**)0x86a63c;
}
