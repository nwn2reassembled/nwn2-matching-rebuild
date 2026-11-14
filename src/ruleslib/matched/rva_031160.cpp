struct Legacy {
    static unsigned char __stdcall getByte(const void* ptr);
};

unsigned char Legacy::getByte(const void* ptr) {
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(ptr)+0x5BF);
}

