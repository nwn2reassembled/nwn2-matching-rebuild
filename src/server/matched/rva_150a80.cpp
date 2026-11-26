struct Field370 {
    unsigned char reserved[0x370];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field370::getValue() { return value; }
