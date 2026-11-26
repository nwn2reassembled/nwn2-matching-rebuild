struct Foo {
    unsigned char flag0;          // +0x00
    unsigned char pad0[0x37];
    unsigned int  valueA;         // +0x38
    unsigned char pad1[0x34];
    unsigned int  valueB;         // +0x70

    unsigned int GetValue();
};

unsigned int Foo::GetValue() {
    if (this->flag0 != 0)
        return this->valueA;
    return this->valueB;
}
