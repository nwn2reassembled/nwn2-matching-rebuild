struct Entry
{
    char data[0x124];
};

class Container
{
public:
    Entry* Get(unsigned char index);
private:
    char prefix[0x14];
    unsigned char count;
    char gap[0xf7];
    Entry entries[1];
};

Entry* Container::Get(unsigned char index)
{
    if (index < count)
    {
        return &entries[index];
    }
    return 0;
}
