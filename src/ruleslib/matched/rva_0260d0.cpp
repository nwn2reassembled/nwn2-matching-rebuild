class X { public: int f(void* p); };
int X::f(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x134);
}
