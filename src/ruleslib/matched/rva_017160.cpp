struct MyClass {
    unsigned char pad[0x014C];
    int field;
    int func(char);
};

int MyClass::func(char x) {
    return ((int)x << 5) + field;
}
