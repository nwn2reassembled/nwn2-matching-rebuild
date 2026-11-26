struct Obj
{
    char padding[0x334];
    char value;
};

char __stdcall GetValue(Obj* obj)
{
    return obj->value;
}
