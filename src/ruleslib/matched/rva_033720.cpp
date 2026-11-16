class MyClass {
public:
    unsigned char getByte(void* ptr);
};

unsigned char MyClass::getByte(void* ptr) {
    return static_cast<unsigned char>(static_cast<char*>(ptr)[71]); // 0x47 == 71 decimal
}

