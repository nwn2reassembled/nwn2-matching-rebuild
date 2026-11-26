struct Object
{
    unsigned char pad[0x2cd];
    char value;
};

char __stdcall GetValue(const Object* obj)
{
    return obj->value;
}
