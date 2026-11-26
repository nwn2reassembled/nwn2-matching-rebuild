struct Object
{
    char unused[0x50];
    unsigned char value;
};

unsigned char __stdcall GetValue(Object* object)
{
    return object->value;
}
