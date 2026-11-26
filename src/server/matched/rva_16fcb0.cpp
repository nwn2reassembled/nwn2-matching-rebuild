struct Field5dc {
    unsigned char reserved[0x5dc];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field5dc::getValue() { return value; }
