struct Entry
{
    unsigned char data[0x124];
};

class EntryTable
{
public:
    Entry* Get(unsigned char index);

private:
    unsigned char header[0x14];
    unsigned char count;
    unsigned char gap[0x10c - 0x15];
    Entry entries[1];
};

Entry* EntryTable::Get(unsigned char index)
{
    if (index < count)
        return &entries[index];

    return 0;
}
