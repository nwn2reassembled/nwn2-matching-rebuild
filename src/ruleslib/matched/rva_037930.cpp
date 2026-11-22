struct MyClass {
    unsigned char getByte(const void* ptr);
};

unsigned char MyClass::getByte(const void* ptr) {
    const unsigned char* p = reinterpret_cast<const unsigned char*>(ptr);
    return *(p + 0x5e);
}

