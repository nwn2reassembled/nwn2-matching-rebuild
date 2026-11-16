struct X {
    static int __stdcall m(void* p);
};

int __stdcall X::m(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x184);
}

