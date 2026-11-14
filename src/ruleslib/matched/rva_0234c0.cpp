struct Legacy {
    unsigned char pad[124];
    unsigned char table[256];
    unsigned char getByte(unsigned char);
};

unsigned char Legacy::getByte(unsigned char idx) {
    unsigned char range = static_cast<unsigned char>(idx - 1);
    if (range <= 39)
        return table[idx];
    return 0;
}
