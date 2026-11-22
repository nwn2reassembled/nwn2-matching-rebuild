struct Legacy {
    char pad[0x304];
    int value;
    int getValue() const;
};

int Legacy::getValue() const { return value; }
