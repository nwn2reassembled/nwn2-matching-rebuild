struct Legacy {
    unsigned char getByte(const unsigned char* ptr);
};

unsigned char Legacy::getByte(const unsigned char* ptr) {
    return ptr[0x629];
}

