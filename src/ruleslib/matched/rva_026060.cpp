class Legacy {
public:
    void* GetValue(void* ptr);
};

void* Legacy::GetValue(void* ptr) {
    return *(void**)((char*)ptr + 0x118);
}

