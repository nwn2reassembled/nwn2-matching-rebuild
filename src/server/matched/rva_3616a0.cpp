struct Legacy {
    int test() const;
};

int Legacy::test() const {
    unsigned int val = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this)+0xd0);
    return val != 0 ? 1 : 0;
}

