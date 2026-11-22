struct MyClass {
    void* foo(int);
};

void* MyClass::foo(int n) {
    return (void*)((char*)this + n * 8 + 0x17c);
}

