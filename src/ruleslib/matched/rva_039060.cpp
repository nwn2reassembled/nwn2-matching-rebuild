struct RulesEngine {
    unsigned char pad0[0x28C];
    int entryCount;
    void* entries;

    void* __stdcall GetEntry(int index);
};

void* RulesEngine::GetEntry(int index) {
    if (index >= 0 && index < entryCount)
        return (void*)((char*)entries + index * 36);
    return 0;
}
