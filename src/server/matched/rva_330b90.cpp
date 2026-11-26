struct SomeClass {
    unsigned char pad_00[0x40];
    int field_40;

    int GetField40();
};

int SomeClass::GetField40() {
    return this->field_40;
}
