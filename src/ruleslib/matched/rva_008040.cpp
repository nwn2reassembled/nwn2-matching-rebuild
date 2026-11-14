struct Legacy {
    char padding[0x88];
    unsigned char data[10];
    void setByte(unsigned char index, unsigned char value);
};

void Legacy::setByte(unsigned char index, unsigned char value) {
    if (index >= 10)
        return;
    data[index] = value;
}

