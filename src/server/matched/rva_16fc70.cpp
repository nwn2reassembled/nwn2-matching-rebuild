struct Field54 {
    unsigned char reserved[0x54];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field54::getValue() { return value; }
