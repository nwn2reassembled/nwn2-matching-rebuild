struct Legacy {
    static unsigned int __stdcall getValue(void* ptr, unsigned char idx);
};

unsigned int __stdcall Legacy::getValue(void* ptr, unsigned char idx) {
    return *reinterpret_cast<unsigned int*>(
        static_cast<char*>(ptr) + 0x198 + static_cast<int>(idx)*4
    );
}
