class Foo {
public:
    int getValue() const;
};

int Foo::getValue() const { return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(this) + 12); }
