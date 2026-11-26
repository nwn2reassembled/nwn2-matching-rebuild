struct Field30 {
    unsigned char reserved[0x30];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field30::getValue() { return value; }
