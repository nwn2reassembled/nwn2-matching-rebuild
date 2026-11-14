struct Legacy {
    unsigned char pad1[0x13c];
    unsigned int flag;
    unsigned char pad2[0x27c - (0x13c + 4)];
    unsigned int input;
    int index;
    unsigned int process(unsigned int value);
};

unsigned int Legacy::process(unsigned int value) {
    unsigned int mask;
    input = value;
    if (value == 0 || flag == 0)
        goto absent;
    for (index = 1; index < 25; ++index) {
        mask = 1u << (index - 1);
        if (value & mask)
            goto found;
    }
absent:
    return 0;
found:
    input = value & ~mask;
    return mask;
}
