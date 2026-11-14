struct Legacy {
    unsigned char pad[0x585];
    unsigned char table[256];
    unsigned char get(unsigned char idx) const;
};

unsigned char Legacy::get(unsigned char idx) const {
    if ((unsigned char)(idx - 1) <= 0x27)
        return table[idx];
    return 0;
}
