class Foo {
public:
    unsigned int get();
};

unsigned int Foo::get() {
    return *(unsigned int*)((char*)this + 0x14);
}

