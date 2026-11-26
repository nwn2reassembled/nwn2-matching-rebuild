struct EngineContext {
    char pad0[0x1B8];
    void* field_1B8;
    char pad1[0x14];
    void* field_1D0;

    void* Resolve(int selector);
};

void* EngineContext::Resolve(int selector) {
    if (selector == 0) {
        return *(void**)field_1B8;
    }
    if (selector == 1) {
        return *(void**)field_1D0;
    }
    return 0;
}
