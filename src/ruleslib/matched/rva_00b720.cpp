struct Legacy {
    char padding[0x18];
    void* table;
    long threshold;
    unsigned short Get(unsigned short idx) const;
};

unsigned short Legacy::Get(unsigned short idx) const {
    if (static_cast<long>(idx) >= threshold)
        return 0xFFFFU;
    return *reinterpret_cast<const unsigned short*>(
        reinterpret_cast<const char*>(table) + idx*2);
}
