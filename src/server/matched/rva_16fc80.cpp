struct Field8c {
    unsigned char reserved[0x8c];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field8c::getValue() { return value; }
