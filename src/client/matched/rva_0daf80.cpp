struct Object
{
    unsigned char pad0[0xbd];
    unsigned char flagsBD;
    unsigned char pad1[0x86];
    unsigned int value144;
    unsigned char pad2[4];
    unsigned char flags14C;

    void SetValue(unsigned int value);
};

void Object::SetValue(unsigned int value)
{
    if (value != value144)
    {
        flagsBD |= 8;
        value144 = value;

        unsigned char flags = flags14C;
        if (flags & 8)
        {
            flags |= 2;
            flags14C = flags;
        }
    }
}
