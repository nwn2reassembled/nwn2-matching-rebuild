class Legacy {
public:
    int getMaskedValue(const void* ptr);
};

int Legacy::getMaskedValue(const void* ptr) {
    return *(int*)((const char*)ptr + 0x318) & 0xffff00;
}

