struct MyClass {
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;          // offset 0x14 from start of object
    int value;       // target field at offset 0x14
    void setValue(int v);
};

void MyClass::setValue(int v) {
    this->value = v;
}

