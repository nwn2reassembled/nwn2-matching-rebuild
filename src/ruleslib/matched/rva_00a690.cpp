class MyLegacy {
public:
    struct Entry {
        unsigned int ptr;
        int count;
        unsigned int dummy;
    };
    char pad[0x10];
    Entry entries[10];
    int func(unsigned char idx, unsigned short val);
};

int MyLegacy::func(unsigned char idx, unsigned short val) {
    if (idx >= 10)
        return 0;
    const Entry &e = entries[idx];
    int cnt = e.count;
    int matches = 0;
    if (cnt > 0) {
        const unsigned short *arr = reinterpret_cast<const unsigned short*>(e.ptr);
        do {
            if (*arr == val)
                ++matches;
            ++arr;
        } while (--cnt);
    }
    return matches;
}
