struct Entry
{
    unsigned char reserved[0x10];
    void* object;
    unsigned int value;
};

class EntryCollection
{
public:
    int Collect(unsigned int* mask);

private:
    unsigned char padding[0x58];
    Entry* entries;
    int count;
};

int EntryCollection::Collect(unsigned int* mask)
{
    *mask = 0;

    int n = count;
    if (n == 0)
        return 0;

    for (int i = 0; i < n; ++i)
    {
        Entry* entry = entries + i;
        if (entry->object == 0)
            return 0;

        *mask |= entry->value;
    }

    return 1;
}
