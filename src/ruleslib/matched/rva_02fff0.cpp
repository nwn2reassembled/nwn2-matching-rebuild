struct MyStruct {
    static unsigned char __stdcall foo(void *p);
};

unsigned char __stdcall MyStruct::foo(void *p) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p)+0x62);
}

