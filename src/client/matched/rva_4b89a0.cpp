struct Widget {
    unsigned char pad0[0x18];
    int initialized;
    int cachedA;
    int cachedB;
    int pad1[5];
    int a;
    int b;

    void EnsureInitialized();
};

void Widget::EnsureInitialized() {
    if (initialized == 0) {
        cachedA = a;
        cachedB = b;
        initialized = 1;
    }
}
