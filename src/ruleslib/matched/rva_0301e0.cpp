struct MyStruct {
    static void __stdcall setByte(void* p, unsigned char val);
};

void MyStruct::setByte(void* p, unsigned char val) {
    *((unsigned char*)((char*)p + 0x60)) = val;
}

