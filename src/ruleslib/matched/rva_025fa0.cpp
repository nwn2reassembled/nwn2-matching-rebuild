struct MyClass {
    unsigned int getValue(unsigned int *p);
};

unsigned int MyClass::getValue(unsigned int *p) { return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p)+0x230); }
