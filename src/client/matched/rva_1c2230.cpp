struct MyClass {
    char pad[0x31c];
    int value;
    void setValue(unsigned int v);
};

void MyClass::setValue(unsigned int v) { value = static_cast<int>(v); }
