struct ServerObject {
    int count;          // +0x00
    void* entries;      // +0x04, array of 0xF4-byte records

    void* GetEntry(int index);
};

void* ServerObject::GetEntry(int index) {
    void* table = entries;
    if (table == 0 || index < 0 || index >= count) {
        return 0;
    }
    return (char*)table + index * 0xF4;
}
