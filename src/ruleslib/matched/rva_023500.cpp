struct Legacy {
    int header;
    unsigned char data[41];
    unsigned char getByte(unsigned char idx) const;
};

unsigned char Legacy::getByte(unsigned char idx) const {
    unsigned char tmp = idx - 1;
    if (tmp <= 39)
        return data[idx];
    return 0;
}
