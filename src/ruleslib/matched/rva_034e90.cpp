struct MyStruct {
    void setByte(void* p, unsigned char val);
};

void MyStruct::setByte(void* p, unsigned char val) {
    ((unsigned char*)p)[0x14] = val;
}

