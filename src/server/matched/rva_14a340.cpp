struct B;

struct A {
    char pad0[4];
    B* ptr;
    int foo();
};

struct B {
    char pad1[0x10070];
    int value;
};

int A::foo() { return ptr->value; }

