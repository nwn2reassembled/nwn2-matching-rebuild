struct Field2c {
    unsigned char reserved[0x2c];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field2c::getValue() { return value; }
