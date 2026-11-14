struct Legacy {
    unsigned char pad[0xd4];
    unsigned char thresholds[40];
    unsigned char* tables[40];
    unsigned char method(unsigned char, unsigned char);
};

unsigned char Legacy::method(unsigned char a1, unsigned char a2) {
    if (a1 > 40)
        return 40;
    if (a1 >= 1) {
        unsigned int index = (unsigned char)(a1 - 1u);
        if (a2 < thresholds[index])
            return tables[index][a2];
    }
    return (unsigned char)-1;
}
