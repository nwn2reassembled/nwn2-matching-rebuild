class Legacy {
public:
    unsigned char readByteAtOffset(void* ptr);
};

unsigned char Legacy::readByteAtOffset(void* ptr) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x55);
}
