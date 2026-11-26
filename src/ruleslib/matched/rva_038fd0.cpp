struct Record {
    unsigned char bytes[0x9c];
};

Record* __stdcall GetEntry(void* table, unsigned short index)
{
    unsigned short available = *(unsigned char*)((char*)table + 0x15b);
    if (index < available) {
        char* base = *(char**)((char*)table + 0x170);
        return (Record*)(base + (unsigned)index * 0x9c);
    }
    return 0;
}
