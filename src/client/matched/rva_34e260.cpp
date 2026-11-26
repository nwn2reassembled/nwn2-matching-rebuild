struct SubObject
{
    unsigned char pad[0xC1];
    unsigned char flagC1;
};

struct SomeClass
{
    unsigned char pad[0x110];
    SubObject* field_110;
    void SetFlagAtC1(unsigned char value);
};

void SomeClass::SetFlagAtC1(unsigned char value)
{
    SubObject* obj = field_110;
    if (obj != 0)
        obj->flagC1 = value;
}
