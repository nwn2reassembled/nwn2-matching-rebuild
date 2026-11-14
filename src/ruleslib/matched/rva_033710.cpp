class Legacy {
public:
    unsigned char getByte(const void* p);
};

unsigned char Legacy::getByte(const void* p) {
    return *reinterpret_cast<const unsigned char*>((const char*)p + 0x46);
}

