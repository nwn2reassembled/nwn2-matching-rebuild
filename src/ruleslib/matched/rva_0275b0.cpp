class MyClass {
public:
    // Static member function with __stdcall calling convention
    static unsigned int __stdcall getC(const struct S* p);
};

struct S {
    unsigned int a;
    unsigned int b;
    unsigned int c;   // offset +0x8 from the start of the structure
};

unsigned int MyClass::getC(const struct S* p) {
    return p->c;
}

