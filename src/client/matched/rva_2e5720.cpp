struct MyStruct {
    unsigned char dummy[0x15c];
    unsigned short value;

    void setByte(unsigned char v);
};

void MyStruct::setByte(unsigned char v) {
    value = v;
}

