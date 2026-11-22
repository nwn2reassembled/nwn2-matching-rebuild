class MyClass {
public:
    unsigned char pad[0x90];
    unsigned char flag;
    void toggle(unsigned char arg);
};

void MyClass::toggle(unsigned char arg) {
    unsigned char temp = (arg << 5) ^ flag;
    temp &= 0x20;
    flag ^= temp;
}

