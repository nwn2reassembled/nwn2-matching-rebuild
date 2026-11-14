struct Foo {
    unsigned int bar(int);
};

unsigned int Foo::bar(int n) {
    if (n == -1)
        return ~0u;
    return 1u << n;
}
