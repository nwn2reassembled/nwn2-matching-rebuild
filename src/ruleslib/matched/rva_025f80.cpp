struct SubStruct {
    char padding[0x228];
    int value;
};

class MyClass {
public:
    int getValue(SubStruct* p);
private:
    int dummy;
};

int MyClass::getValue(SubStruct* p) {
    return p->value;
}

