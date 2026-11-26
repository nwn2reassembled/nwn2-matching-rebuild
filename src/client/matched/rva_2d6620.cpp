struct Element
{
    unsigned char bytes[0x5c];
};

struct ElementTable
{
    unsigned char reserved0[0x84];
    Element* elements;
    int reserved1;
    int count;

    Element* Get(int index);
};

Element* ElementTable::Get(int index)
{
    if (index < 0 || index >= count)
        return 0;

    return &elements[index];
}
