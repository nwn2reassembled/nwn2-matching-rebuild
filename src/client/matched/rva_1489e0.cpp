struct Base {
    int dummy;
};

struct B {
    char pad[0x100dc];
    void* field;
};

class A : public Base {
public:
    B* ptr;
    void method(B* arg);
};

void A::method(B* arg) {
    ptr->field = arg;
}

