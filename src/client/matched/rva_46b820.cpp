struct MyClass {
    char pad[0x3a4];
    int field;
    void setVal(int);
};

void MyClass::setVal(int v) { field = v; }
