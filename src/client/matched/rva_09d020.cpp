struct MyClass {
    int padding[51];
    int value;
    int getValue() const;
};

int MyClass::getValue() const { return value; }
