struct Foo {
    char dummy[212];
    int value;
};

class MyClass {
public:
    static int __stdcall getField(const Foo* p);
};

int MyClass::getField(const Foo* p) { return p->value; }
