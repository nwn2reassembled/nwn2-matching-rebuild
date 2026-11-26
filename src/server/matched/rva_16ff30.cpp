struct Field98 {
    unsigned char reserved[0x98];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field98::getValue() { return value; }
