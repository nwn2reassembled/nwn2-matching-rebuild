struct Legacy {
    unsigned char readByte(const void *p) const;
};

unsigned char Legacy::readByte(const void *p) const {
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(p)+0x15c);
}
