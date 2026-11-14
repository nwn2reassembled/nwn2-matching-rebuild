struct MyClass {
    static unsigned char __stdcall foo(unsigned int ptr);
};

unsigned char __stdcall MyClass::foo(unsigned int ptr) {
    return *reinterpret_cast<unsigned char*>(ptr + 0x44);
}
