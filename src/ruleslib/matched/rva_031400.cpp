struct MyStruct {
    void setByteAtOffsetX(void* ptr, unsigned char value);
};

void MyStruct::setByteAtOffsetX(void* ptr, unsigned char value) {
    *(unsigned char *)((char*)ptr + 0x5e4) = value;
}

