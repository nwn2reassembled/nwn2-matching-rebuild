struct EntryTable {
    int field_0;
    int field_4;
    unsigned short* entries;

    unsigned short GetEntry(int index);
};

unsigned short EntryTable::GetEntry(int index) {
    if (index < field_0)
        return entries[index];
    return 0xFFFF;
}
