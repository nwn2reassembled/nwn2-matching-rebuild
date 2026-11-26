struct Obj
{
    char pad[0x84];
    int value;
};

void __stdcall SetObjValue(Obj* obj)
{
    obj->value = 1;
}
