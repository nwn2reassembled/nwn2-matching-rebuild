struct MyClass {
    char padding[672];
    int value;
    int getValue() const;
};

int MyClass::getValue() const { return value; }
