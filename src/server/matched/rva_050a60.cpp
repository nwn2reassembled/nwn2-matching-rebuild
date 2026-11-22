class MyClass {
public:
    int member; // ordinary data member
    static int __stdcall foo(int a, int b, int c);
};

int __stdcall MyClass::foo(int a, int b, int c) {
    return 0;
}

