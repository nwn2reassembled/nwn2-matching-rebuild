struct Legacy {
    unsigned char pad[0x55];
    unsigned char data[41];
    unsigned char getByte(unsigned char idx);
};

unsigned char Legacy::getByte(unsigned char idx) {
    if ((unsigned char)(idx - 1) <= 0x27)
        return data[idx];
    return 0;
}
