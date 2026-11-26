struct Foo
{
    char pad[0x5E8];
    int field;
};

void __stdcall SetField(Foo* obj, int value)
{
    obj->field = value;
}
