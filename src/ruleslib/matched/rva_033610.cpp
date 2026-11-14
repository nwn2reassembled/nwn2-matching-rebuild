struct Legacy {
    unsigned char getByte(void* ptr);
};

unsigned char Legacy::getByte(void* ptr) {
    return *reinterpret_cast<unsigned char*>(static_cast<char*>(ptr)+0x42);
}

