class MyClass {
public:
    int foo(unsigned);
};

int MyClass::foo(unsigned v) {
    return (v <= 1u);
}

