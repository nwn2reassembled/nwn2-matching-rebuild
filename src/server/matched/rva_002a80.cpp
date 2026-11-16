class X {
public:
    int f();
};

int X::f() { return *reinterpret_cast<int*>(0x864410); }
