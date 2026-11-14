extern "C" unsigned int __cdecl strlen(const char*);

struct Legacy {
    const char* data;
    unsigned char getByte(int idx) const;
};

unsigned char Legacy::getByte(int idx) const {
    if (idx >= 0) {
        const char* p = data;
        if (p && strlen(p) > static_cast<unsigned int>(idx))
            return static_cast<unsigned char>(p[idx]);
    }
    return 0;
}
