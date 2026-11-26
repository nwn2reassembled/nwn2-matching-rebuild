class Foo
{
public:
    unsigned char gap0[0xA70];
    unsigned int field_A70;
    unsigned char gapA74[0x2C];
    unsigned int field_AA0;

    void SetThing(unsigned int value);
};

void Foo::SetThing(unsigned int value)
{
    field_A70 = value;
    if (value == 1)
    {
        field_AA0 = value;
    }
}
