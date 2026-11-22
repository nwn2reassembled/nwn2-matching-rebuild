struct Legacy {
    char pad[0x4b8];
    unsigned short value;
    unsigned short getValue() const;
};

unsigned short Legacy::getValue() const {
    return value;
}

