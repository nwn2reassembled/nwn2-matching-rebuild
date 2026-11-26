struct Foo {
    int dummy;
    void* ptr;
    unsigned int check();
};

unsigned int Foo::check() {
    return (*(int*)((char*)ptr + 0x10190) != 0);
}
