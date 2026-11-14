struct Legacy {
    unsigned char dummy[48];            // ordinary data member, size enough for offset 0x26
    unsigned char getByte(const void* ptr) const;
};

unsigned char Legacy::getByte(const void* ptr) const {
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(ptr) + 38);
}
