struct MyClass {
    char pad[0x700];
    unsigned char byteField;

    void setByte(unsigned char value);
};

void MyClass::setByte(unsigned char value) {
    this->byteField = value;
}
