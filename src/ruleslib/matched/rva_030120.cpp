class MyClass {
public:
    unsigned char getByte(const void* ptr);
};

unsigned char MyClass::getByte(const void* ptr) {
    const unsigned char* p = static_cast<const unsigned char*>(ptr);
    return p[0x75];
}
