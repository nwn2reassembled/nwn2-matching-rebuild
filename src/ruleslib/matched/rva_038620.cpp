struct MyStruct {
    static void __stdcall SetField(MyStruct* obj, unsigned int value);
};

void __stdcall MyStruct::SetField(MyStruct* obj, unsigned int value) {
    *(unsigned int*)((char*)obj + 0x9c) = value;
}

