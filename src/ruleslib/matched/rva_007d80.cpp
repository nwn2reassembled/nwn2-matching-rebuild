struct MyClass {
    unsigned char pad1[0x140];
    void* arrayBase;
    unsigned char pad2[16];
    unsigned short threshold;
    int method(unsigned short param);
};

int MyClass::method(unsigned short param) {
    if (param < threshold) {
        unsigned long index = static_cast<unsigned long>(param) * 180ul;
        const unsigned char* base = static_cast<const unsigned char*>(arrayBase) + index;
        if (*(const unsigned int*)(base + 0x84) == 0) {
            if (*(const unsigned int*)(base + 0x80) != 0)
                return 1;
        }
    }
    return 0;
}
