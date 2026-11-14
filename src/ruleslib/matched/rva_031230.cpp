struct Legacy {
    short readWord(const void* ptr) const;
};

short Legacy::readWord(const void* ptr) const {
    return *reinterpret_cast<const short*>(static_cast<const char*>(ptr)+0x55C);
}
