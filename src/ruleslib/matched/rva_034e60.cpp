struct Legacy {
    static signed char __stdcall getByte(const unsigned char* base, signed char idx);
};

signed char __stdcall Legacy::getByte(const unsigned char* base, signed char idx) {
    return *(base + 0x10 + static_cast<int>(idx));
}

