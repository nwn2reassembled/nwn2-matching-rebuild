struct MyStruct {
    void setValue(void* base, unsigned char index, unsigned short value);
};

void MyStruct::setValue(void* base, unsigned char index, unsigned short value) {
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(base) + 0x28 + (index * 2)) = value;
}
