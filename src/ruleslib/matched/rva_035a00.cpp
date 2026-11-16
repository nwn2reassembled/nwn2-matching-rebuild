class Legacy {
public:
    unsigned char getByte(const void* ptr);
};

unsigned char Legacy::getByte(const void* ptr) {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(ptr) + 0x29c);
}

