struct ElementView {
    unsigned char prefix[16];
    unsigned int ptr;
    int count;
};

struct Container {
    unsigned short getWord(unsigned char idx, unsigned char subidx);
};

unsigned short Container::getWord(unsigned char idx, unsigned char subidx) {
    if (idx >= 10u) return 0xFFFF;
    const ElementView &e = *reinterpret_cast<const ElementView*>(reinterpret_cast<const char*>(this) + idx * 12);
    if (subidx >= e.count) return 0xFFFF;
    unsigned short *arr = reinterpret_cast<unsigned short*>(e.ptr);
    return arr[subidx];
}
