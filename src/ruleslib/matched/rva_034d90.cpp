struct MyStruct {
    unsigned char pad[6];
    unsigned char value;
    static void __stdcall setByte(MyStruct* obj, unsigned char val);
};

void MyStruct::setByte(MyStruct* obj, unsigned char val) {
    obj->value = val;
}

