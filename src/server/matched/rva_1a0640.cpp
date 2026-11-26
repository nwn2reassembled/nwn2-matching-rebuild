struct ServerTable {
    unsigned char GetField(unsigned char index);
    unsigned char pad[0x434];
};

unsigned char ServerTable::GetField(unsigned char index) {
    if (index >= 4)
        return 0;
    return *(unsigned char*)((char*)this + 0x115 + index * 0x124);
}
