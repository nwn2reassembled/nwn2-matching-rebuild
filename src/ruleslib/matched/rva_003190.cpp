struct Legacy {
    unsigned char pad1[0x15c];
    unsigned char threshold;
    unsigned char pad2[23];
    unsigned int base;

    int compute(unsigned short arg);
};

int Legacy::compute(unsigned short arg) {
    if (arg < threshold)
        return base + ((unsigned int)arg << 6);
    else
        return 0;
}

