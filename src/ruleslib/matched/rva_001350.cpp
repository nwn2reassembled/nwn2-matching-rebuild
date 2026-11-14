struct MyClass {
    unsigned char pad[0x7D];
    unsigned char data[256];
    unsigned char func(unsigned char);
};

unsigned char MyClass::func(unsigned char param) {
    if ((unsigned char)(param - 1) <= 39)
        return data[param];
    return 0;
}
