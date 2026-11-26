class EntryTable {
public:
    char pad0[0x314];
    unsigned int field314;
    unsigned int field318;
    char pad1[8];
    unsigned int field324;
    unsigned int field328;
    char pad2[0x560 - 0x32C];
    unsigned int entry560;
    unsigned int entry564;
    unsigned int entry568;
    unsigned int entry56C;

    void CopyEntry(int index);
};

void EntryTable::CopyEntry(int index)
{
    if (index >= 1)
    {
        EntryTable* entry = (EntryTable*)((char*)this + index * 68);
        this->field314 = entry->entry560;
        this->field318 = entry->entry564;
        this->field324 = entry->entry568;
        this->field328 = entry->entry56C;
    }
}
