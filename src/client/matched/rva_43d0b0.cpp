struct MyClass {
    char padding[0x4c];
    int value;
    void setValue(int);
};

void MyClass::setValue(int v) {
    this->value = v;
}
