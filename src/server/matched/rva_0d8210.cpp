class SomeClass
{
public:
    char pad_00[0x24];
    unsigned int field_24;

    char SetSomething(unsigned int value);
};

char SomeClass::SetSomething(unsigned int value)
{
    if (value == 0)
    {
        return 0;
    }

    if (field_24 == 0)
    {
        field_24 = value;
    }

    return 1;
}
