struct B;

struct A {
    char pad[4];
    B* ptr;
    int func();
};

int A::func() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x2ec);
}

