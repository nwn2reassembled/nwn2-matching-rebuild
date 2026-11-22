struct Bar;

struct Foo {
    int dummy;
    Bar* ptr;
    int bar();
};

int Foo::bar() {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x10084);
}

