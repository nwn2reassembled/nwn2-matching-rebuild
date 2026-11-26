class MyClass {
public:
    unsigned int foo() const;
private:
    char dummy[4];
    void* p; // stored at offset 0x04
};

unsigned int MyClass::foo() const {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p) + 0x100fc);
}

