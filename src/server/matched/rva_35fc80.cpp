struct C {
    unsigned char pad[0x55d];
    unsigned char table[0x100];
    unsigned char get(unsigned char a);
};

unsigned char C::get(unsigned char a) {
    unsigned char b = a - 1;
    if (b <= 0x27)
        return table[a];
    return 0;
}
