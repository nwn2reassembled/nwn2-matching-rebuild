struct MyClass {
    unsigned char padding[0x88];
    unsigned char data[10];
    unsigned char getByte(unsigned char);
};

unsigned char MyClass::getByte(unsigned char idx) {
    if (idx >= 10)
        return 0;
    return data[idx];
}
