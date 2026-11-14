class C {
public:
    static int __stdcall f(int);
};

int __stdcall C::f(int a) {
    return a + 0x94;
}

