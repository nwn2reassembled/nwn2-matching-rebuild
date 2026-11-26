struct Entry
{
    unsigned int value;
    unsigned int reserved1;
    unsigned int reserved2;
    unsigned int other;
};

struct Container
{
    char prefix[0x98];
    unsigned short count;
    unsigned short reserved;
    Entry* entries;
};

int __cdecl GetEntryValues(const Container* container, unsigned int index, unsigned int* first, unsigned int* second)
{
    if (first == 0 || second == 0)
        return 6;

    if (index >= container->count)
        return 0x8e;

    *first = container->entries[index].value;
    *second = container->entries[index].other;
    return 0;
}
