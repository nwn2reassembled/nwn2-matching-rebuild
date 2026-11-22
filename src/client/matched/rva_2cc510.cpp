struct B {
    char padding[0x3a0];
    int flag;
};

struct A {
    int dummy;
    B* ptr;
    void set_flag();
};

void A::set_flag() {
    ptr->flag = 1;
}

