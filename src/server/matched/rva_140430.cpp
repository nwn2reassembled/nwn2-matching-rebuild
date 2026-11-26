int ContainsPlayerId(void* table, int playerId) {
    void* entry = *(void**)((char*)table + 0x818);
    while (entry != 0) {
        if (*(int*)((char*)entry + 0x20) == playerId)
            return 1;
        entry = *(void**)((char*)entry + 0x24);
    }
    return 0;
}
