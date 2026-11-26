struct Legacy {
    void* ptr;
    unsigned short value() const;
};

unsigned short Legacy::value() const {
    return *reinterpret_cast<unsigned short*>(static_cast<char*>(ptr) + 0x70);
}
