struct Field08 {
    unsigned char reserved[8];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field08::getValue() { return value; }
