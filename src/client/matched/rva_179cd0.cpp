class MyClass {
    unsigned char _pad0[20];
public:
    int field_a;
    int field_b;

    void foo(int a, int b);
};

void MyClass::foo(int a, int b) {
    this->field_a = a;
    this->field_b = b;
}

