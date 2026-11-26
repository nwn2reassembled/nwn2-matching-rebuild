struct Inventory {
    unsigned char pad[0x294];
    int count;              // +0x294
    void* records;          // +0x298

    void* GetRecord(int index); // original single emitted function
};

void* Inventory::GetRecord(int index) {
    if (index < 0 || index >= count) {
        return 0;
    }
    return (void*)((char*)records + index * 20);
}
