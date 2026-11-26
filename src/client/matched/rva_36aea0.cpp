struct CInventoryTable {
    unsigned char pad0[0x27c];
    void* entries;
    unsigned char pad1[0x284 - 0x27c - 4];
    unsigned int count;

    void* GetEntry(int index);
};

void* CInventoryTable::GetEntry(int index)
{
    if (index >= 0 && index < (int)this->count)
        return (char*)this->entries + index * 0x2c;
    return 0;
}
