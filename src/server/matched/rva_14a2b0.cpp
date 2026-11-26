struct A {
    int dummy;
    void* ptr;
    int foo();
};

int A::foo() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x1008c);
}
