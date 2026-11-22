struct MyStruct {
    int dummy;
    void* inner;
    int foo();
};

int MyStruct::foo() {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(inner) + 0x36c );
}

