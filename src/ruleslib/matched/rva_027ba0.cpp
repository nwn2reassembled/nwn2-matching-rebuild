class C {
public:
    static char __stdcall foo(void* ptr);
};

char C::foo(void* ptr) {
    char* p = (char*)ptr;
    return *(p + 0x2f4);
}
