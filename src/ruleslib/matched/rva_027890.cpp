struct S {
    static unsigned char __stdcall getByte(const void* p);
};

unsigned char __stdcall S::getByte(const void* p) {
    const unsigned char* ptr = static_cast<const unsigned char*>(p);
    return ptr[0x39];
}
