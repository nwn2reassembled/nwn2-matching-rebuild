class Foo {
public:
    Foo* GetSelf();
    // ...
};

Foo* Foo::GetSelf()
{
    return this;
}
