class MyClass {
public:
    unsigned char foo(const void* p);
};

unsigned char MyClass::foo(const void* p) {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(p)+0x13);
}

