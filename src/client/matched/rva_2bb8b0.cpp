struct MyClass {
    char pad[440];
    unsigned long zeroField;
    void clear();
};

void MyClass::clear() { zeroField = 0; }
