struct Object
{
    unsigned char padding[0x159];
    unsigned char value;
};

bool __stdcall lessThan(Object *object, unsigned char x)
{
    return object->value > x;
}
