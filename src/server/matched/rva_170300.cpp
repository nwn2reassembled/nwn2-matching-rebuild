struct Field14 {
    unsigned char reserved[0x14];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field14::getValue() { return value; }
