struct Legacy {
    unsigned char getByte(void* p);
};

unsigned char Legacy::getByte(void* p) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p)+0x5f5);
}
