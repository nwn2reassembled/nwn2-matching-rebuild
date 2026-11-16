struct MyClass {
    static int __stdcall foo(int);
};

int __stdcall MyClass::foo(int x) { return x + 72; }
