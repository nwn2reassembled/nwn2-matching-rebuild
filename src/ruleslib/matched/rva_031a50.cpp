struct Legacy {
    unsigned char get(const void *ptr);
};

unsigned char Legacy::get(const void *ptr) {
    const unsigned char* base = reinterpret_cast<const unsigned char*>(ptr);
    return base[0x62d];
}

