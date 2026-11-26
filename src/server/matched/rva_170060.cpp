struct Field5c {
    unsigned char reserved[0x5c];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field5c::getValue() { return value; }
