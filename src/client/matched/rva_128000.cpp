struct B {
    char pad[0x38];
    int value;
};

struct A {
    B* ptr;
    int func();
};

int A::func() {
    return ptr->value;
}

