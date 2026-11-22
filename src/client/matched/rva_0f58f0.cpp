class MyClass {
    unsigned int m_value;
public:
    unsigned int compute(unsigned int arg);
};

unsigned int MyClass::compute(unsigned int arg) {
    return (arg << 4) + this->m_value;
}
