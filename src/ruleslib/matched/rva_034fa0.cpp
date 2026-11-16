struct MyStruct {
    static void __stdcall setField(void* ptr, int value);
};

void MyStruct::setField(void* ptr, int value) {
    *((int*)((char*)ptr + 0x58)) = value;
}

