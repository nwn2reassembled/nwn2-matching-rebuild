class X {
public:
    void f(void* p);
};

void X::f(void* p) {
    *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x80) = 0;
}
