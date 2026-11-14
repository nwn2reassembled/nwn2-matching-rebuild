struct Legacy {
    unsigned int dummy;
    unsigned char data[6];
    void setByte(unsigned char);
};

void Legacy::setByte(unsigned char b) {
    for (unsigned int i = 0; i < 6; ++i)
        data[i] = b;
}
