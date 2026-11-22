class Legacy {
public:
    unsigned char getByte(const void* ptr);
};

unsigned char Legacy::getByte(const void* ptr) {
    const unsigned char* p = static_cast<const unsigned char*>(ptr);
    return *(p + 0x2e0);
}
