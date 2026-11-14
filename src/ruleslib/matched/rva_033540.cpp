class MyStruct {
public:
    char pad[0xb0];
    unsigned int value;
};

class MyClass {
public:
    unsigned int getValue(MyStruct* p);
};

unsigned int MyClass::getValue(MyStruct* p) { return p->value; }

