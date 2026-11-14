struct MyStruct {
    int field0;
    int field1;
    int field2;
    unsigned char byte3;
};

class MyClass {
public:
    void func(MyStruct* p, int, int);
};

void MyClass::func(MyStruct* p, int, int) {
    p->field0 = 0;
    p->field1 = 0;
    p->field2 = 0;
    p->byte3 &= 0xF0;
}

