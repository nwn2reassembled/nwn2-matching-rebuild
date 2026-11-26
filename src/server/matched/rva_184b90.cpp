class Foo {
public:
    Foo* getThis();
};

Foo* Foo::getThis() {
    return this;
}

