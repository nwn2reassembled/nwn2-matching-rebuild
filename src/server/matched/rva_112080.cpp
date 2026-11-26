struct Legacy {
    char pad[0x108];
    unsigned int value;
    unsigned int getValue();
};

unsigned int Legacy::getValue() {
    return this->value;
}

