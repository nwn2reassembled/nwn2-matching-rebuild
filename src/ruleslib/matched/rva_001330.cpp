struct Legacy {
    unsigned char data[0x100];
    unsigned char lookup(unsigned char idx) const;
};

unsigned char Legacy::lookup(unsigned char idx) const {
    if ((unsigned char)(idx - 1) <= 39)
        return data[0xa5 + idx];
    return 0;
}
