struct B {
    char pad[108];
    int value;
};

class A {
public:
    virtual ~A() {}
    int getValue();
private:
    B* ptr_;
};
int A::getValue() { return ptr_->value; }
