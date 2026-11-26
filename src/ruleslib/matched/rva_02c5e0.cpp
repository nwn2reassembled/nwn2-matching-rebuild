struct Foo {
    char data[0x57C];
};

unsigned int __cdecl GetFooSize()
{
    return sizeof(Foo);
}
