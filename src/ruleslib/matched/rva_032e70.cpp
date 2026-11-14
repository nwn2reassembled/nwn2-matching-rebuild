struct Legacy {
    unsigned short getValue(const void* ptr) const;
};

unsigned short Legacy::getValue(const void* ptr) const {
    return *reinterpret_cast<const unsigned short*>(static_cast<const char*>(ptr)+2);
}

