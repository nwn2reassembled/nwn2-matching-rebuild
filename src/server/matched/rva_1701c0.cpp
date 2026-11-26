struct Field350 {
    unsigned char reserved[0x350];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field350::getValue() { return value; }
