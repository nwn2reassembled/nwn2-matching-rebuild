class Dummy {
public:
    static unsigned short __stdcall foo(void*);
};

unsigned short __stdcall Dummy::foo(void* p) {
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p)+0x154);
}
