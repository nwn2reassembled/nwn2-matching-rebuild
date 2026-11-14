class MyClass {
public:
    unsigned short field0;
    char pad1[2];
    unsigned int fieldA;
    unsigned short dummy;
    unsigned int fieldB;
    MyClass* init();
};

MyClass* MyClass::init() {
    field0 = 0xffff;
    fieldA = 0;
    fieldB = 0;
    return this;
}
