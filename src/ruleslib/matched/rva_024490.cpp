struct Legacy {
    int legacyFunction(const void* arg);
};

int Legacy::legacyFunction(const void* arg) {
    return ((*(const unsigned char*)((const char*)arg + 12)) >> 2) & 1;
}
