struct Element {
    int a;
    int b;
    int c;
};

struct ElementTable {
    char reserved[0x558];
    Element* elements;
    unsigned short count;
    Element* Get(unsigned short index);
};

Element* ElementTable::Get(unsigned short index)
{
    if (index < count)
        return elements + index;
    return 0;
}
