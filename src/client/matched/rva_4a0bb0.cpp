struct LookupTable
{
    char reserved[0x6C];
    int* entries;
    int count;

    int Get(unsigned char index) const;
};

int LookupTable::Get(unsigned char index) const
{
    if (index >= count)
        return 0;

    return entries[index];
}
