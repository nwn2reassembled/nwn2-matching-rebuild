class Legacy {
public:
    static unsigned char __stdcall getByte(void* ptr);
};

unsigned char __stdcall Legacy::getByte(void* ptr) {
    return reinterpret_cast<unsigned char*>(ptr)[0x45];
}

