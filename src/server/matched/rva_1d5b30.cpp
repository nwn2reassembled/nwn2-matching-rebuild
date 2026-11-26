struct Foo {
    void* f0;
    void* f4;
    void* f8;
    void* fC;
    void* f10;

    Foo* Init(void* a, void* b);
};

Foo* Foo::Init(void* a, void* b)
{
    f8 = 0;
    fC = 0;
    f10 = 0;
    f0 = a;
    f4 = b;
    return this;
}
