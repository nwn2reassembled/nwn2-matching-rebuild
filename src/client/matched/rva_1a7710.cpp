class X {
public:
    void* foo();
};

void* X::foo() { return reinterpret_cast<void*>(reinterpret_cast<char*>(this)+0x3a0); }
