extern "C" unsigned int __cdecl strlen(const char*);

struct Legacy {
    const char* ptr;
    unsigned int len() const;
};

unsigned int Legacy::len() const {
    if (!ptr)
        return 0;
    return strlen(ptr);
}
