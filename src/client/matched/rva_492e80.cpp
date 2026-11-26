struct MyStruct {
    unsigned char pad0[44];
    unsigned int field2c;
    unsigned int field30;
    unsigned char pad1[4];
    unsigned int field38;
    unsigned int field3c;
    unsigned char pad2[4];
    unsigned char byte44;
    unsigned char byte45;
    void func();
};

void MyStruct::func() {
    field30 = field2c;
    field3c = field38;
    byte44 = byte45;
}

