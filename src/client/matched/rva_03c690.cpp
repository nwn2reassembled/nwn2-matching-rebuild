struct MyClass
{
    char padding[0x5c];
    int value;
    int getValue() const;
};

int MyClass::getValue() const { return value; }

