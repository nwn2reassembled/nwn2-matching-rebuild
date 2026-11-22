class Legacy {
public:
    int getValue(const void* ptr) const;
};

int Legacy::getValue(const void* ptr) const {
    return *(int*)((char*)ptr + 0x98);
}

