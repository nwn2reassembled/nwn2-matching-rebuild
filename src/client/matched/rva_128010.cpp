struct Sub { char pad[56]; int target; };

struct MyClass {
    Sub* ptr;
    void method(int mask);
};

void MyClass::method(int mask) {
    this->ptr->target &= ~mask;
}

