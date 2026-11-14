struct Legacy {
    unsigned char readByte(void* ptr);
};

unsigned char Legacy::readByte(void* ptr) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x5f4);
}

