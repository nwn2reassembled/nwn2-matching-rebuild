struct Foo
{
    char padding[0xfe];
    unsigned short value;

    void SetValue(unsigned short v);
};

void Foo::SetValue(unsigned short v)
{
    value = v;
}
