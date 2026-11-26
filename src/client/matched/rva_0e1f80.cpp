class Obj {
public:
    char pad0[0x200];
    int *items;          // 0x200
    int count;           // 0x204
    char pad1[0x28];
    unsigned char flags; // 0x230
    char pad2[3];
    int index;           // 0x234

    int GetElement();
};

int Obj::GetElement()
{
    if ((flags & 0x08) == 0)
        return 0;
    if (index < 0 || index >= count)
        return 0;
    return items[index];
}
