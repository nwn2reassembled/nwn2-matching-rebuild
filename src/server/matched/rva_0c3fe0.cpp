struct Legacy {
    char pad[200];
    unsigned int value;
    unsigned int getValue() const;
};

unsigned int Legacy::getValue() const { return value; }

