struct MyClass {
    int data;
    int foo(void* p);
};

int MyClass::foo(void* p) {
    return *reinterpret_cast<int*>((char*)p + 0x5f0);
}

