class ItemTable {
    unsigned char pad[0x3E];
    unsigned short entries[27];
public:
    unsigned short GetEntry(int index);
};

unsigned short ItemTable::GetEntry(int index)
{
    if ((unsigned int)index <= 0x1a)
        return entries[index];
    return 0xFFFF;
}
