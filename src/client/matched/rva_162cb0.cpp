struct Foo {
    unsigned short bar();
};

unsigned short Foo::bar() { return 0xFFFF; }

