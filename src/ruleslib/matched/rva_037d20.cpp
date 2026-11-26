struct Object
{
    char reserved[0x60];
    int value;
};

void __stdcall SetObjectValue(Object* object, int value)
{
    object->value = value;
}
