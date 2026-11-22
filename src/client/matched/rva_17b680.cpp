struct Legacy {
    char pad[0xf28];
    unsigned int field;
    int foo(unsigned int mask);
};

int Legacy::foo(unsigned int mask) {
    return !!(field & mask);
}
