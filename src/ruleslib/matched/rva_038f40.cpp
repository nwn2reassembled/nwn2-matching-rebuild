struct Entry {
    int fields[7];
};

struct EntryTable {
    char pad[0x10];
    Entry* entries;      /* 0x10 */
    char pad2[4];        /* 0x14 */
    int entryCount;      /* 0x18 */
};

struct Container {
    char pad[0x138];
    EntryTable* table;
};

Entry* __stdcall GetEntry(Container* container, int index)
{
    EntryTable* table = container->table;
    if (index < 0 || index >= table->entryCount) {
        return 0;
    }
    return &table->entries[index];
}
