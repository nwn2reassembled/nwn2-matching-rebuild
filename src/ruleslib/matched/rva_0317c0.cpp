class MyClass {
public:
    unsigned int foo(void* p);
};

unsigned int MyClass::foo(void* p) {
    return *reinterpret_cast<unsigned short*>(static_cast<char*>(p)+0x618);
}

