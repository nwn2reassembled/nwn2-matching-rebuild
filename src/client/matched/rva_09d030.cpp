struct Legacy {
    char padding[0xBC];
    int value;
    int getValue() const;
};

int Legacy::getValue() const { return value; }
