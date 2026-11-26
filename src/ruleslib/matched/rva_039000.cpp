void* __stdcall GetEntryFromTable(void* table, unsigned short index) {
    if (index < (unsigned short)*((unsigned char*)((unsigned char*)table + 0x15C)))
        return (void*)(*(unsigned int*)((unsigned char*)table + 0x174) + ((unsigned int)index << 6));
    return 0;
}
