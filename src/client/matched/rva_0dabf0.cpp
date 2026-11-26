struct Foo {
    unsigned char pad[0x14c];
    unsigned char flags;

    void __thiscall SetBit3(unsigned char value);
};

void Foo::SetBit3(unsigned char value)
{
    if (((flags >> 3) & 1) != value)
    {
        flags = ((value << 3) ^ flags) & 8 ^ flags | 2;
    }
}
