struct MyClass {
    char _pad0[12];          // 0x00 - 0x0b
    int field_0xc;           // 0x0c
    int field_0x10;          // 0x10
    int field_0x14;          // 0x14
    int _pad1;               // 0x18 (unused padding)
    int field_0x1c;          // 0x1c
    int _pad2;               // 0x20 (unused padding)
    int field_0x24;          // 0x24

    void init(int, int);
};

void MyClass::init(int a, int b) {
    this->field_0x24 = 0;   // zero at offset 0x24 (first store)
    this->field_0xc = 0;    // zero at offset 0x0c
    this->field_0x10 = 0;   // zero at offset 0x10
    this->field_0x14 = b;   // second arg into offset 0x14
    this->field_0x1c = a;   // first arg into offset 0x1c
}

