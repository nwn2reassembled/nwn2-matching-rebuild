struct MyStruct {
    char pad[0x28];
    unsigned int value;
    static void __stdcall setField(MyStruct* p, unsigned int val);
};

void MyStruct::setField(MyStruct* p, unsigned int val) {
    p->value = val;
}
