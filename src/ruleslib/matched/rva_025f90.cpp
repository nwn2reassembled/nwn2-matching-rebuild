class Legacy {
public:
    static unsigned int __stdcall ReadField(void* p);
};

unsigned int Legacy::ReadField(void* p) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p)+0x22C);
}

