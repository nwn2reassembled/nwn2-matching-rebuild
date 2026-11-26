struct Object
{
    char padding[0x20];
    unsigned int value;
};

unsigned int __stdcall GetObjectValue(const Object* object)
{
    return object->value;
}
