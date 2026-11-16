struct S { char data[0x1F4]; unsigned int value; };

class MyClass {
public:
    static unsigned int __stdcall foo(S* p);
};

unsigned int MyClass::foo(S* p) { return p->value; }

