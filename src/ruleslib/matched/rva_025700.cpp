struct MyStruct {
    char pad[0x10c];
    unsigned int field_10c;
    static void __stdcall setField(MyStruct* ptr, unsigned int val);
};

void MyStruct::setField(MyStruct* ptr, unsigned int val) { ptr->field_10c = val; }
