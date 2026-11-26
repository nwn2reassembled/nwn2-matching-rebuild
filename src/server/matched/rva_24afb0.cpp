class SomeClass
{
public:
    char pad_0000[0x4B8];
    unsigned short field_4B8;
    unsigned short GetField4B8();
};

unsigned short __thiscall SomeClass::GetField4B8()
{
    return field_4B8;
}
