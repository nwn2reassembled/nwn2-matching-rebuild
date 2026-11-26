struct Foo {
    Foo* __fastcall self();
};

Foo* Foo::self()
{
    return this;
}
