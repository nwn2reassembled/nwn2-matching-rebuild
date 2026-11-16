class X {
public:
    int __stdcall foo(unsigned char a);
};

int X::foo(unsigned char a) { return a < 2 ? 1 : 0; }
