struct X {
    unsigned char __stdcall f(int a, int b, int c, int d);
};

unsigned char X::f(int a, int b, int c, int d) { return 0; }
