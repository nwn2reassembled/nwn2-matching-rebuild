struct MyStruct {
    unsigned char dummy[0x324];
    unsigned short value;
    unsigned short getValue();
};

unsigned short MyStruct::getValue() {
    return value;
}
