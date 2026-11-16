struct Legacy {
    static void __stdcall method(unsigned int idx, unsigned char base, unsigned char val);
};

void Legacy::method(unsigned int idx, unsigned char base, unsigned char val) {
    *reinterpret_cast<unsigned char*>(static_cast<unsigned long>(base)+idx+0x10) = val;
}

