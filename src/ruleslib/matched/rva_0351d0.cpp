struct MyStruct {
    unsigned char getByte(const void* ptr, unsigned int idx);
};

unsigned char MyStruct::getByte(const void* ptr, unsigned int idx) {
    const unsigned char* base = static_cast<const unsigned char*>(ptr);
    return base[idx + 16];
}
