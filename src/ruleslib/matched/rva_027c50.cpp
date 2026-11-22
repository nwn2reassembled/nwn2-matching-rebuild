struct Foo {
    int getValue(int* p);
};

int Foo::getValue(int* p) {
    return *(int*)((char*)p + 0x31c);
}

