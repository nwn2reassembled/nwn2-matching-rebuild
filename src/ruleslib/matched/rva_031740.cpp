struct Legacy {
    int func(unsigned int, unsigned char);
};

int Legacy::func(unsigned int a, unsigned char b) {
    return a + b * 24u + 0x464;
}
