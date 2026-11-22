struct Legacy {
    unsigned char getByte(const Legacy* obj) const;
};

unsigned char Legacy::getByte(const Legacy* obj) const {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(obj)+0x2e4);
}
