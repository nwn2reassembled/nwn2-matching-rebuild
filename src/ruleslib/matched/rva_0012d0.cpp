struct Legacy {
    unsigned char padding[0x55d];
    unsigned char data[41];
    unsigned char getByte(unsigned char idx) const;
};

unsigned char Legacy::getByte(unsigned char idx) const {
    unsigned char i = idx;
    --i;
    if (i <= 39)
        return data[idx];
    return 0;
}
