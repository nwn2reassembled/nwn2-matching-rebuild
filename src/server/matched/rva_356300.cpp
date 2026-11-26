class CStringTable {
public:
    unsigned short GetAt(unsigned short index);

    unsigned char pad[0x18];
    unsigned short *entries;
    int count;
};

unsigned short CStringTable::GetAt(unsigned short index)
{
    if ((int)index >= count) {
        return 0xFFFF;
    }
    return entries[index];
}
