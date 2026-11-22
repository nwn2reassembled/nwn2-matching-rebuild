class MyClass {
public:
    unsigned int getValue();
private:
    int dummy;      // offset 0
    void* m_ptr;     // offset 4
};

unsigned int MyClass::getValue() {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(m_ptr) + 0x32c);
}
