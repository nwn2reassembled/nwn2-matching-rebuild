struct MyClass {
    int foo();
};

int MyClass::foo() {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(
        *reinterpret_cast<int**>( reinterpret_cast<char*>(this) + 0x6c8 )
    ) + 0x60 );
}
