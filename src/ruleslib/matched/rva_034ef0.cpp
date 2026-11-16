struct Legacy {
    unsigned char getByte(void* ptr);
};
unsigned char Legacy::getByte(void* ptr) {
    return *reinterpret_cast<unsigned char*>(
        reinterpret_cast<char*>(ptr)+0x1d);
}

