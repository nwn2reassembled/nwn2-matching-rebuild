class MyClass {
public:
    unsigned char foo(void* p);
};

unsigned char MyClass::foo(void* p) {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(p) + 0x60);
}

