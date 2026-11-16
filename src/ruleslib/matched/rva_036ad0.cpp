class Legacy {
public:
    unsigned char getByte(const void* base, int offset);
};

unsigned char Legacy::getByte(const void* base, int offset) {
    const char* ptr = static_cast<const char*>(base);
    return *reinterpret_cast<const unsigned char*>(ptr + offset + 4);
}

