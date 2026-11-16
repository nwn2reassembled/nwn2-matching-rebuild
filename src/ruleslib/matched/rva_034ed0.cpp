struct Legacy {
    unsigned char getByte(const void* ptr) const;
};

unsigned char Legacy::getByte(const void* ptr) const {
    return *reinterpret_cast<const unsigned char*>(static_cast<const unsigned char*>(ptr) + 0x1C);
}
