struct Field620 {
    unsigned char reserved[0x620];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field620::getValue() { return value; }
