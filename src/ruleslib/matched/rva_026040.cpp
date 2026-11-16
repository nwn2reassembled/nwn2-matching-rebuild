class Foo {
public:
    int getValue(void* p);
};

int Foo::getValue(void* p) {
    return *reinterpret_cast<int*>(static_cast<char*>(p)+0x110);
}
