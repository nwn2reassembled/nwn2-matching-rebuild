struct MyClass {
    int a;
    int b;
    int val;
    void setValue(int value);
};

void MyClass::setValue(int value) {
    this->val = value;
}

