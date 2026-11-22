struct MyStruct {
    static unsigned char __stdcall getByte(const unsigned char* ptr, unsigned int idx);
};

unsigned char __stdcall MyStruct::getByte(const unsigned char* ptr, unsigned int idx) {
    return *(ptr + idx + 2);
}
