class MyClass {
public:
    unsigned int compute(unsigned int base, unsigned int index);
};

unsigned int MyClass::compute(unsigned int base, unsigned int index) {
    return base + index * 8u + 32u;
}

