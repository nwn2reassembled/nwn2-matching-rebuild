struct Field24 {
    unsigned char reserved[0x24];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field24::getValue() { return value; }
