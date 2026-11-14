class Legacy {
public:
    static unsigned char __stdcall getByte(unsigned char* base, int offset);
};

unsigned char Legacy::getByte(unsigned char* base, int offset) {
    return *(base + offset + 0x24);
}

