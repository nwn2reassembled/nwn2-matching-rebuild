struct Target {
    int field0;
    int field1;
    int field2; // offset 8
};

class Foo {
public:
    void setField(Target* p, int val);
};

void Foo::setField(Target* p, int val) {
    p->field2 = val;
}

