class MyClass {
public:
    bool compareWithByte(unsigned char arg);
private:
    unsigned int placeholder;
};

bool MyClass::compareWithByte(unsigned char arg) {
    const unsigned int field = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this)+4);
    return reinterpret_cast<const unsigned char*>(field)[0x50] == arg;
}
