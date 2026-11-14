class Legacy {
public:
    unsigned char readByteAtOffset2(const void* ptr);
};

unsigned char Legacy::readByteAtOffset2(const void* ptr) {
    return reinterpret_cast<const unsigned char*>(ptr)[2];
}

