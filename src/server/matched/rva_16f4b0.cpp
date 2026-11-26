struct Field04 {
    unsigned char reserved[4];
    unsigned int value;
    unsigned int getValue();
};
unsigned int Field04::getValue() { return value; }
