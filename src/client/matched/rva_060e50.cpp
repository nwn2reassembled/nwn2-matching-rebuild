struct Legacy {
    unsigned long getPtr();
};

unsigned long Legacy::getPtr() { return reinterpret_cast<unsigned long>(this) + 0x1e0; }
