struct Legacy {
    int padding1;          // offset 0x00
    char padding2[4];      // offset 0x04-0x07
    int padding3;          // offset 0x08-0x0B
    int padding4;          // offset 0x0C-0x0F
    int value;             // offset 0x10-0x13

    int getValue() const;
};

int Legacy::getValue() const {
    return value;
}

