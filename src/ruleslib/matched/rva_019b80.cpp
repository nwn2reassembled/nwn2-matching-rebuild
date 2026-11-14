struct MyStruct {
    unsigned char pad[0x29c];
    unsigned char myByte;
    void setByte(unsigned char);
};

void MyStruct::setByte(unsigned char arg) {
    switch (arg) {
    case 1:
        myByte = 0x1e;
        break;
    default:
        myByte = 0x14;
        break;
    }
}
