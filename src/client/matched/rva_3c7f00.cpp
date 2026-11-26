class MyClass {
public:
    void setZero();
private:
    int a; // offset 0
    int b; // offset 4
    int c; // offset 8
};

void MyClass::setZero() {
    c = 0;
}

