struct MyClass {
    char pad0[64];
    int field40;
    char pad1[12];
    int field50;

    void func(int);
};

void MyClass::func(int arg) {
    int temp = arg - this->field50;
    this->field40 = temp;
}

