struct CObject
{
    void SetValue(unsigned int value);

    unsigned char pad0[0xbd];
    unsigned char flagsA;
    unsigned char pad1[0x7a];
    unsigned int valueField;
    unsigned char pad2[0x10];
    unsigned char flagsB;
};

void CObject::SetValue(unsigned int value)
{
    if (value != valueField)
    {
        flagsA |= 8;
        flagsB |= 2;
        valueField = value;
    }
}
