struct Field34c {
    unsigned char reserved[0x34c];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field34c::getValue() { return value; }
