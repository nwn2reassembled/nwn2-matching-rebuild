struct Param {
    char pad[0x2E8];
    unsigned int field;
};

class MyClass {
public:
    unsigned int func(Param* p);
};

unsigned int MyClass::func(Param* p) {
    return p->field;
}

