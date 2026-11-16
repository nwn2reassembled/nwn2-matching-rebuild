struct MyStruct {
    static void __stdcall setByte(void* ptr, unsigned char b);
};

void MyStruct::setByte(void* ptr, unsigned char b) {
    ((unsigned char*)ptr)[9] = b;
}

