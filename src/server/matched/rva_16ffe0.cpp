struct Field60 {
    unsigned char reserved[0x60];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field60::getValue() { return value; }
