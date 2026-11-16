struct Legacy {
    unsigned long getField(const void* p);
};

unsigned long Legacy::getField(const void* p) {
    // Return the 32‑bit value located at offset 0x120 from the object pointed to by p.
    return *reinterpret_cast<const unsigned long*>(static_cast<const char*>(p) + 0x120);
}

