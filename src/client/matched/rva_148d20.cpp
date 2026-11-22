class C {
public:
    virtual ~C() {}
    int* ptr;
    int foo();
};

int C::foo() {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(ptr) + 0x10078 );
}

