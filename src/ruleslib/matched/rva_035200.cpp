class Legacy {
public:
    unsigned char getByte(void* ptr, unsigned int idx);
};

unsigned char Legacy::getByte(void* ptr, unsigned int idx) {
    return *reinterpret_cast<unsigned char*>(
        reinterpret_cast<char*>(ptr) + idx + 0x16
    );
}

