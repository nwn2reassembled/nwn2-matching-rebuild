class Counter {
public:
    unsigned int count(const char* src, unsigned int len);
};

unsigned int Counter::count(const char* src, unsigned int len) {
    unsigned int i = 0;
    if (len > 0) {
        do {
            unsigned char c = *src;
            if (c == 10 || c == 13)
                break;
            ++i;
            ++src;
        } while (i < len);
    }
    return i;
}
