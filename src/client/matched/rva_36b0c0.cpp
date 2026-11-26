struct ItemTableEntry { int pad0[10]; };

class ItemTable {
public:
    ItemTableEntry* __thiscall GetEntry(int index);

private:
    char pad[0x288];
    ItemTableEntry* entries;   // +0x288
    int field_28C;             // +0x28c
    int entryCount;            // +0x290
};

ItemTableEntry* ItemTable::GetEntry(int index) {
    if (index < 0 || index >= entryCount)
        return 0;
    return reinterpret_cast<ItemTableEntry*>(
        reinterpret_cast<char*>(entries) + index * 0x2c);
}
