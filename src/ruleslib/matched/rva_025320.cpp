struct Target {
    char padding[0x168];
    int field;
};

class MyClass {
public:
    void setField(Target*, int);
};

void MyClass::setField(Target* t, int v) {
    t->field = v;
}
