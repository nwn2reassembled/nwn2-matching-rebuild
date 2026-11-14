class C {
public:
    static int __stdcall foo(int);
};

int C::foo(int x) {
    return x + 108;
}

