struct SomeItem
{
    char reserved[0x64];
    void* value;
    char tail[4];
};

struct SomeContainer
{
    char reserved0[0x15a];
    unsigned char count;
    char reserved1[0x11];
    SomeItem* items;

    void* Get(unsigned short index);
};

void* SomeContainer::Get(unsigned short index)
{
    SomeItem* item = index < count ? &items[index] : (SomeItem*)0;
    return item->value;
}
