struct Legacy {
    void* a;
    unsigned long foo() const;
};

unsigned long Legacy::foo() const {
    unsigned long base = *reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(this)+4);
    return *reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(base)+0x100ec);
}

