struct MyStruct {
    static void __stdcall SetField(MyStruct* obj, unsigned char val);
    char padding[17];
    char field;
};

void MyStruct::SetField(MyStruct* obj, unsigned char val) {
    obj->field = val;
}

