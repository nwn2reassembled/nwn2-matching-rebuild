class Legacy {
public:
    static int __stdcall readFlag(void* p);
};

int Legacy::readFlag(void* p) {
    unsigned char val = *reinterpret_cast<unsigned char*>(static_cast<char*>(p) + 0x6d0);
    return (val >> 4) & 1;
}

