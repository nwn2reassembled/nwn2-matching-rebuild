struct MyStruct {
    char pad0[12];          // offset 0x00 – 0x0b
    unsigned short field0c; // offset 0x0c (WORD)
    char pad1[2];           // padding to align next DWORD at 0x10
    unsigned int field10;   // offset 0x10 (DWORD)
    unsigned int field14;   // offset 0x14 (DWORD)
    unsigned int field18;   // offset 0x18 (DWORD)
    unsigned int field1c;   // offset 0x1c (DWORD)
    unsigned int field20;   // offset 0x20 (DWORD)
    unsigned int field24;   // offset 0x24 (DWORD)
    unsigned int field28;   // offset 0x28 (DWORD)
    char pad2[20];          // padding to reach next DWORD at 0x40
    unsigned int field40;   // offset 0x40 (DWORD)
    unsigned int field44;   // offset 0x44 (DWORD)
    unsigned char field48;  // offset 0x48 (BYTE)

    int clear();            // method declaration
};

int MyStruct::clear() {
    this->field14 = 0;
    this->field18 = 0;
    this->field0c = 0;
    this->field10 = 0;
    this->field1c = 0;
    this->field20 = 0;
    this->field24 = 0;
    this->field28 = 0;
    this->field40 = 0;
    this->field44 = 0;
    this->field48 = 0;
    return 1;
}

