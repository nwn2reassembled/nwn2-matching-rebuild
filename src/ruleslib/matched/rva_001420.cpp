struct Legacy {
    unsigned char data[512];
    unsigned char lookup(unsigned char a1, unsigned char a2);
};

unsigned char Legacy::lookup(unsigned char a1, unsigned char a2) {
    if ((unsigned char)(a1 - 1) <= 39) {
        if (a2 < data[0xd3 + a1]) {
            unsigned int* table = *(unsigned int**)(data + 0xd0);
            if (table)
                return ((unsigned char*)table[a1 - 1])[a2];
        }
    }
    return 0;
}
