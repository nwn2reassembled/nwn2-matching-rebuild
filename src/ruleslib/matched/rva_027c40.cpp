struct Target {
    char padding[0x318];
    int value;
};

class MyClass {
public:
    int getValue(Target* p);
};

int MyClass::getValue(Target* p) {
    return p->value;
}

