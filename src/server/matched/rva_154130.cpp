struct Field4c {
    unsigned char reserved[0x4c];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field4c::getValue() { return value; }
