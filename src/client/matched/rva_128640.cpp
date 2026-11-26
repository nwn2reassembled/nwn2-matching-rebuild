struct Entry {
    unsigned int key;
    unsigned int value;
};

struct EntryTable {
    unsigned char reserved[0x20];
    Entry* entries;
    int count;

    unsigned int Get(int index) const;
};

unsigned int EntryTable::Get(int index) const {
    if (index < 0 || index >= count)
        return 0;
    return entries[index].value;
}
