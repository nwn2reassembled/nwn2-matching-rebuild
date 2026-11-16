struct Foo {
    static unsigned char __stdcall getByte(void* p);
};

unsigned char __stdcall Foo::getByte(void* p) {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(p)+0x15a);
}

