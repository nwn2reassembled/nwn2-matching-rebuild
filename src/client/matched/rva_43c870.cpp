struct MyClass {
    char pad[0x24];
    int field1;
    int field2;
    void setFields(int a, int b);
};

void MyClass::setFields(int a, int b) {
    field1 = a;
    field2 = b;
}

