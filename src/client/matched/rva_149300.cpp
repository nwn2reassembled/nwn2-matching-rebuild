struct MyClass {
    int dummy;
    int value;
    int func() const;
};

int MyClass::func() const { return value + 0x10198; }
