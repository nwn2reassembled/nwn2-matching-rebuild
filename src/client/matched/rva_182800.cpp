struct Element64
{
    char data[64];
};

class ElementList
{
public:
    Element64* At(unsigned short index);

private:
    char gap0[0x15c];
    unsigned char count;
    char gap1[0x174 - 0x15d];
    Element64* items;
};

Element64* ElementList::At(unsigned short index)
{
    if (index < count)
        return items + index;

    return 0;
}
