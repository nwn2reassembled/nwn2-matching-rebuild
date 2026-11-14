class MyClass {
public:
    unsigned char getByte(unsigned char* ptr);
};

unsigned char MyClass::getByte(unsigned char* ptr) {
    return *(ptr + 0x5e4);
}

