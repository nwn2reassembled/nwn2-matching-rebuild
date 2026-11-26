struct Foo
{
    char padding[0x60c];
    int value;
};

void __stdcall SetValue(Foo* object, int value)
{
    object->value = value;
}
