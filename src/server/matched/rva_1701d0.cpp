struct Field354 {
    unsigned char reserved[0x354];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field354::getValue() { return value; }
