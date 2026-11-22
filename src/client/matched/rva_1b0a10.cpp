class A {
public:
    int f();
};

int A::f() { return *reinterpret_cast<int*>((char*)this + 0x3b0); }

