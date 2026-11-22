struct MyClass {
    unsigned short getValue(const void* ptr);
};

unsigned short MyClass::getValue(const void* ptr) {
    return *(const unsigned short*)((const char*)ptr + 0x72);
}

