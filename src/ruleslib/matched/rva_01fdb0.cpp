struct LegacyClass {
    unsigned char pad[0x2f0];
    const unsigned short* table;
    unsigned char limit;
    unsigned short lookup(unsigned char);
};

unsigned short LegacyClass::lookup(unsigned char idx) {
    if (idx >= limit)
        return 0xffff;
    return table[idx];
}
