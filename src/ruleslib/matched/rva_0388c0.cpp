class X {
public:
    unsigned char f(int);
};

unsigned char X::f(int p) { return *(unsigned char*)((char*)p + 0x16); }
