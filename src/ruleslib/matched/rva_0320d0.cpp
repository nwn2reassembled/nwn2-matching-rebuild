struct Target {
    char padding[0x74];
    unsigned int field;
};

class MyClass {
public:
    void setField(Target* t, unsigned int value);
};

void MyClass::setField(Target* t, unsigned int value) {
    t->field = value;
}

