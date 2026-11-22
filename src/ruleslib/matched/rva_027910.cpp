class MyClass {
public:
    unsigned char getByte(void* ptr);
};

unsigned char MyClass::getByte(void* ptr) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x51);
}

