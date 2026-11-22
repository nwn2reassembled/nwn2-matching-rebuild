class MyClass {
public:
    void foo();
};

void MyClass::foo() {
    ((unsigned char*)this)[0xb4] &= 0xdf;
}

