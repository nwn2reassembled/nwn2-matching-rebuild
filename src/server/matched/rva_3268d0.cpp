struct C
{
    unsigned char prefix[0x3a4];
    int field_3a4;
    void SetField(int value);
};

void C::SetField(int value)
{
    field_3a4 = value;
}
