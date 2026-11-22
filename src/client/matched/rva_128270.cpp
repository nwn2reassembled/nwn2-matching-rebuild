struct Legacy {
    unsigned char getValue() const;
    char pad[29];
    unsigned char value; // offset 0x1d
};

unsigned char Legacy::getValue() const { return value; }

