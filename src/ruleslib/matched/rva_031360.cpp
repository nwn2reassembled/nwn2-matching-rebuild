class Legacy {
public:
    static unsigned char __stdcall func(unsigned int base, unsigned char offset);
};

unsigned char __stdcall Legacy::func(unsigned int base, unsigned char offset) {
    return *reinterpret_cast<unsigned char*>(base + static_cast<unsigned int>(offset) + 0x5b8);
}
