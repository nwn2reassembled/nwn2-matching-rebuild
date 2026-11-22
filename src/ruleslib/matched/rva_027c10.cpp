class Legacy {
public:
    unsigned char readByte(unsigned int addr);
};

unsigned char Legacy::readByte(unsigned int addr) {
    return *reinterpret_cast<unsigned char*>(addr + 0x310);
}
