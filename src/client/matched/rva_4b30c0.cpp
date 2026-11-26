struct Legacy {
    unsigned int field0;
    unsigned char flag;
    char padding[0x2b0 - 5];
    Legacy* init();
};

Legacy* Legacy::init() {
    field0 = 0;
    flag = 0;
    unsigned char* base = reinterpret_cast<unsigned char*>(this);
    for (int i = 0; i < 106; ++i) {
        *reinterpret_cast<unsigned int*>(base + 0xA8 + i * 4) = 0;
    }
    return this;
}

