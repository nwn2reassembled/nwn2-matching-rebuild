struct Large {
    char data[96];
};

class MyClass {
public:
    void foo(Large arg);
};

void MyClass::foo(Large arg) { }

