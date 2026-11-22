struct Foo {
    int dummy;
    void* ptr;
    unsigned int getValue() const;
};

unsigned int Foo::getValue() const {
    return *reinterpret_cast<const unsigned int*>(
        reinterpret_cast<unsigned long>(this->ptr) + 0x444 );
}

