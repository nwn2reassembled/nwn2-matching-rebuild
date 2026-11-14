class MyClass {
public:
    static void __stdcall setByte(unsigned int base, unsigned char offset, unsigned char value);
};

void MyClass::setByte(unsigned int base, unsigned char offset, unsigned char value) {
    *reinterpret_cast<unsigned char*>(base + 0x5B8u + offset) = value;
}

