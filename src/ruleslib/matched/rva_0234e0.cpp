class MyClass {
public:
    unsigned char getByte(unsigned char idx);
private:
    char padding[0x54];
    unsigned char data[41];
};

unsigned char MyClass::getByte(unsigned char idx) {
    unsigned char range = static_cast<unsigned char>(idx - 1);
    if (range <= 39)
        return data[idx];
    return 0;
}
