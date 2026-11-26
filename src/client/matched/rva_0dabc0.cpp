struct C {
    unsigned char reserved0[0xbd];
    unsigned char flagsBD;
    unsigned char reserved1[0x82];
    unsigned int value140;
    unsigned char reserved2[0x8];
    unsigned char flags14C;

    void SetValue(unsigned int value);
};

void C::SetValue(unsigned int value) {
    if (value != value140) {
        flagsBD |= 0x08;
        flags14C |= 0x02;
        value140 = value;
    }
}
