struct Foo
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;

    Foo* Reset();
};

Foo* Foo::Reset()
{
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    return this;
}
