struct C {
    char pad0[0x5c];
    unsigned int field_5c;
    char pad1[0x18];
    unsigned int field_78;

    unsigned int SetMask(unsigned int value);
};

unsigned int C::SetMask(unsigned int value) {
    unsigned int old = field_78;
    field_78 = value;
    field_5c = (field_5c & ~old) | value;
    return value;
}
