struct MyClass {
    int padding[225];
    int value;
    int get() const;
};

int MyClass::get() const { return value; }

