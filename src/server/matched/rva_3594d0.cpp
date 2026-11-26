struct EntryTable
{
    unsigned char pad0[0x6C];
    int* entries;
    int count;

    int GetEntry(unsigned char index);
};

int EntryTable::GetEntry(unsigned char index)
{
    if ((int)index >= count)
        return 0;
    return entries[index];
}
