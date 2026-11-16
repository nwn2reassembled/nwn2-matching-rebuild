struct MyStruct {
    void zeroBytes();
};

void MyStruct::zeroBytes() {
    reinterpret_cast<unsigned char*>(this)[4] = 0;
    reinterpret_cast<unsigned char*>(this)[5] = 0;
}
