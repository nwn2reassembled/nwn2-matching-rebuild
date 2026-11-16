class Legacy {
public:
    static unsigned char __stdcall readByte(void* ptr);
};

unsigned char Legacy::readByte(void* ptr) {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr)+0x188);
}
