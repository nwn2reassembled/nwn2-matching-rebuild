struct Field6c {
    unsigned char reserved[0x6c];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field6c::getValue() { return value; }
