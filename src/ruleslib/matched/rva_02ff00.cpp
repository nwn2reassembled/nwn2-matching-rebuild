struct Foo {
    int getValue(void* p);
};

int Foo::getValue(void* p) { return *(int*)((char*)p + 0x84); }
