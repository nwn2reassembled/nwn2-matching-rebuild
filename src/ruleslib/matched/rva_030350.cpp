struct MyStruct {
    static void __stdcall setByte(MyStruct* obj, unsigned char value);
};

void MyStruct::setByte(MyStruct* obj, unsigned char value) {
    *((unsigned char*)((char*)obj + 0x79)) = value;
}
