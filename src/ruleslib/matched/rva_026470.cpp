struct Legacy {
    int dummy;
    unsigned int getValue();
};

unsigned int Legacy::getValue() {
    return 0x00040000u;
}
