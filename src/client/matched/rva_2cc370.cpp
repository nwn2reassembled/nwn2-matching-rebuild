struct B {
    char pad[0x54];
    unsigned long value;
};

class A {
public:
    unsigned long get_value() const;
private:
    char pad[4];
    B* ptr;
};

unsigned long A::get_value() const { return ptr->value; }
