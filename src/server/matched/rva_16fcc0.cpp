struct Field5e0 {
    unsigned char reserved[0x5e0];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field5e0::getValue() { return value; }
