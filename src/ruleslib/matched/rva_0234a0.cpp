struct Legacy {
    char pad[44];
    unsigned char table[41];
    unsigned char getByte(unsigned char idx) const;
};

unsigned char Legacy::getByte(unsigned char idx) const {
    unsigned char range = static_cast<unsigned char>(idx - 1);
    if (range <= 39)
        return table[idx];
    return 0;
}
