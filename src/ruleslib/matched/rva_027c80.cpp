class Legacy {
public:
    static unsigned int __stdcall foo(unsigned int ptr);
};

unsigned int Legacy::foo(unsigned int ptr) { return (*reinterpret_cast<unsigned int*>(ptr + 0x318)) & 0x124a00; }
