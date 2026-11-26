struct Foo {
    int dummy;
    int value;
    int get() const;
};

int Foo::get() const {
    return value + 0x100d4;
}

