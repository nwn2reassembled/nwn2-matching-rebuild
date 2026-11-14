struct MyStruct {
    char pad[0x44];
    unsigned int field;
    static void __stdcall SetField(MyStruct* obj, unsigned int value);
};

void __stdcall MyStruct::SetField(MyStruct* obj, unsigned int value) {
    obj->field = value;
}
