struct Object
{
    unsigned char pad[0x50];
    unsigned int field;
};

void __stdcall SetField(Object* object, unsigned int value)
{
    object->field = value;
}
