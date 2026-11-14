class MyClass {
public:
    unsigned int func(unsigned char param);
};

unsigned int MyClass::func(unsigned char param) {
    return (static_cast<unsigned int>(param) * 0x94u) + reinterpret_cast<unsigned long>(this) + 0xa4u;
}

