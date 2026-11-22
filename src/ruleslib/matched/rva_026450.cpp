struct Foo {
    unsigned long bar();
};

unsigned long Foo::bar() {
    return 0x10000;
}

