class C {
public:
    static int __stdcall f(int);
};

int C::f(int x) { return x + 12; }
