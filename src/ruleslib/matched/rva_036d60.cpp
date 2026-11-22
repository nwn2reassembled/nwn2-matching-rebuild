class Legacy {
public:
    static unsigned char __stdcall getByte(void* p);
};

unsigned char Legacy::getByte(void* p) {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(p)+0x14);
}

