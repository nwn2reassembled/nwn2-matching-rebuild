struct Legacy {
    char pad0[0xc];                     // 0x00-0x0b
    volatile short field_c;             // 0x0c
    char pad1[2];                       // 0x0e-0x0f
    volatile int   field_10;            // 0x10
    volatile int   field_14;            // 0x14
    volatile int   field_18;            // 0x18
    volatile int   field_1c;            // 0x1c
    volatile int   field_20;            // 0x20
    volatile int   field_24;            // 0x24
    volatile int   field_28;            // 0x28
    char pad2[0x14];                    // 0x2c-0x3f
    volatile int   field_40;            // 0x40
    volatile int   field_44;            // 0x44
    volatile unsigned char field_48;    // 0x48

    int clear();
};

int Legacy::clear() {
    this->field_14 = 0;
    this->field_18 = 0;
    this->field_c   = 0;
    this->field_10 = 0;
    this->field_1c = 0;
    this->field_20 = 0;
    this->field_24 = 0;
    this->field_28 = 0;
    this->field_40 = 0;
    this->field_44 = 0;
    this->field_48 = 0;
    return 1;
}

