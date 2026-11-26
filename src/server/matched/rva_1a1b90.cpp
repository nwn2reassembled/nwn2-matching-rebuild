struct Entry
{
    unsigned char data[0x6c];
};

class Container
{
public:
    Entry* Get(unsigned short index);

private:
    unsigned char pad0[0x15a];
    unsigned char count;
    unsigned char pad1[0x11];
    Entry* entries;
};

Entry* Container::Get(unsigned short index)
{
    if (index < count)
        return &entries[index];

    return 0;
}
