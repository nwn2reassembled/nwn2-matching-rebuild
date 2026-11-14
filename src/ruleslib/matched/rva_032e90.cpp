class Legacy {
public:
    int dummy;
    unsigned char readByte(const void* ptr) const;
};

unsigned char Legacy::readByte(const void* ptr) const {
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(ptr)+4);
}

