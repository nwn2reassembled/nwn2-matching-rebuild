struct MyClass {
    char padding[44];
    int value;
    int getValue() const;
};

int MyClass::getValue() const {
    return value;
}
