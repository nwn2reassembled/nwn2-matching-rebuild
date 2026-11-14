struct MyStruct
{
    char pad[0x6c];
    int field;
    static void __stdcall setField(MyStruct* p, int value);
};

void MyStruct::setField(MyStruct* p, int value)
{
    p->field = value;
}

