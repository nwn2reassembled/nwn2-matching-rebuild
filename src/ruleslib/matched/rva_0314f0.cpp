struct SomeClass
{
    char padding[0x5f0];
    int value;
};

void __stdcall SetSomeClassValue(SomeClass* object, int value)
{
    object->value = value;
}
