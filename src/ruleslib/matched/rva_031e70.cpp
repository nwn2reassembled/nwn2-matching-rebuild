struct Param {
    char pad[52];
    unsigned int value;
};

class MyClass {
public:
    unsigned int getValue(Param* p);
};

unsigned int MyClass::getValue(Param* p) {
    return p->value;
}
