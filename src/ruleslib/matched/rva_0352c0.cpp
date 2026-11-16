struct Legacy {
    static void __stdcall setByte(void* ptr, unsigned char value);
};

void Legacy::setByte(void* ptr, unsigned char value) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x28) = value;
}

