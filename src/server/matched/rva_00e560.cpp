struct MyClass {
    unsigned int padding[40];
    unsigned int value;
    void setValue(unsigned int);
};

void MyClass::setValue(unsigned int v) { this->value = v; }
