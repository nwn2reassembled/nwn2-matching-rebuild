class MyClass {
public:
    static int __stdcall foo(int);
};

int MyClass::foo(int param) { return param + 0x8c; }
