class MyClass {
public:
    unsigned char foo(int* p);
};

unsigned char MyClass::foo(int* p) {
    return *reinterpret_cast<unsigned char*>((char*)p + 0x19);
}

