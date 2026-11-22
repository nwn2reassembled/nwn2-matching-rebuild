struct Legacy {
    int getValue(void* ptr);
};

int Legacy::getValue(void* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x204);
}
