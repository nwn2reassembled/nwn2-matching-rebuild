class MyClass {
public:
    int divisor;
    virtual ~MyClass() {}
    int foo(const int* p) const;
};

int MyClass::foo(const int* p) const { return (*p) % divisor; }
