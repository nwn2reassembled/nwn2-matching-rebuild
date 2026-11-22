class Legacy {
public:
    static unsigned short __stdcall getValue(void* ptr);
};

unsigned short Legacy::getValue(void* ptr) {
    return *reinterpret_cast<unsigned short*>(static_cast<char*>(ptr)+0x7E);
}

