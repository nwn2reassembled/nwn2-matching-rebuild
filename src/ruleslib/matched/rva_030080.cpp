class X {
public:
    unsigned short foo(const void* ptr);
};

unsigned short X::foo(const void* ptr) {
    // Return the 16‑bit value located at offset 0x6c from the supplied pointer.
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(ptr)+0x6c);
}

