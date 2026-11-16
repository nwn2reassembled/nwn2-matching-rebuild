struct MyStruct {
    int dummy[21];
    int value;
    static void __stdcall setField(MyStruct* obj, int val);
};

void __stdcall MyStruct::setField(MyStruct* obj, int val) {
    obj->value = val;
}
