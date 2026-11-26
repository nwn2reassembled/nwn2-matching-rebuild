struct Legacy {
    int getValue();
};

int Legacy::getValue() {
    unsigned long base = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 4);
    return *reinterpret_cast<int*>(base + 0x10094);
}
