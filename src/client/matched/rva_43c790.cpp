class MyClass {
public:
    int* getMember();
private:
    int a;
    int b;
    int c;
    int d; // offset 0xC
};

int* MyClass::getMember() {
    return &d;
}

