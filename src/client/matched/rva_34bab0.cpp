struct SomeClass {
    char pad0[0x838];
    unsigned int field_838;
    char pad1[0x12E];
    unsigned char field_96a;

    int IsSpecialState();
};

int SomeClass::IsSpecialState() {
    if (field_838 == 1)
        return 1;
    unsigned char v = field_96a;
    if (v == 2 || v == 3 || v == 14)
        return 1;
    return 0;
}
