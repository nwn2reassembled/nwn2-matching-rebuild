typedef unsigned char u8;

struct Element;

struct Container
{
    u8 pad0[0x14];
    u8 count;
    u8 pad1[0x10c - 0x15];
    Element* GetElement(u8 index);
};

Element* Container::GetElement(u8 index)
{
    if (index < count)
        return (Element*)((char*)this + index * 0x124 + 0x10c);

    return 0;
}
