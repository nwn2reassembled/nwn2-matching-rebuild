struct Legacy {
    char pad[0x1a0];
    unsigned char data[256];
    unsigned int getByte(int index, int mult) const;
};

unsigned int Legacy::getByte(int index, int mult) const {
    return data[index + 7 * mult];
}
