struct FieldA8 {
    unsigned char reserved[0xa8];
    unsigned int value;
    unsigned int getValue();
};
unsigned int FieldA8::getValue() { return value; }
