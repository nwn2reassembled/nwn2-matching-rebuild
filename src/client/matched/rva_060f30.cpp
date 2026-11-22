struct LegacyClass {
    char pad[0x135F];
    unsigned char byteField;
    void setByte(unsigned char);
};

void LegacyClass::setByte(unsigned char value) {
    this->byteField = value;
}

