struct Foo {
    int bar(int*);
};

int Foo::bar(int* p) {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(p)+0x144 );
}

