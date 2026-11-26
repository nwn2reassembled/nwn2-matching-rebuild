struct Foo
{
    unsigned int f0;
    unsigned int f1;
    unsigned int f2;
    unsigned int f3;
    unsigned int f4;
    unsigned int f5;
    unsigned int f6;
    unsigned int f7;
    unsigned int f8;
    unsigned int f9;
    unsigned int f10;
    unsigned int f11;

    Foo* init();
};

Foo* Foo::init()
{
    f0 = 0x80f614;
    f1 = 0;
    f2 = 0;
    f3 = 0;
    f4 = 0;
    f5 = 0;
    f6 = 0;
    f7 = 0;
    f8 = 0;
    f10 = 0;
    f11 = 0;
    f9 = 0;
    return this;
}
