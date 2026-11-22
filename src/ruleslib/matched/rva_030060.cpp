class Legacy {
public:
    static unsigned short __stdcall readWord(void* ptr);
};

unsigned short __stdcall Legacy::readWord(void* ptr) {
    return *reinterpret_cast<unsigned short*>(static_cast<char*>(ptr)+0x68);
}

