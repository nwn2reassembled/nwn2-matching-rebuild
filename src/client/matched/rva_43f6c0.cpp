struct MyClass {
    char pad[12];
    int value;
    int getValue() const;
};

int MyClass::getValue() const {
    return value + 0x3c;
}

