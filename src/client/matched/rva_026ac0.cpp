struct Foo {
    int pad0;
    int pad1;
    int pad2;
    int pad3;
    int pad4;
    int pad5;
    void* field_18;
    unsigned long* getSomething();
};

unsigned long* Foo::getSomething() {
    unsigned long* p = static_cast<unsigned long*>(field_18);
    if (p != 0) {
        return reinterpret_cast<unsigned long*>(p[1]);
    }
    return 0;
}
