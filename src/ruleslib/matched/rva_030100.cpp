class Legacy {
public:
    unsigned char getByte(void* ptr);
};

unsigned char Legacy::getByte(void* ptr) {
    return reinterpret_cast<unsigned char*>(ptr)[0x76];
}
