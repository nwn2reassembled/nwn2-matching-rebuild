struct Foo {
    static unsigned int __stdcall bar(void* b, unsigned short a);
};

unsigned int Foo::bar(void* b, unsigned short a) {
    return (static_cast<unsigned int>(a) << 6)
        + *reinterpret_cast<const unsigned int*>(reinterpret_cast<char const*>(b)+0x17c);
}

