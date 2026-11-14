struct Legacy {
    static void __stdcall writeWord(void* ptr, unsigned short val);
};

void Legacy::writeWord(void* ptr, unsigned short val) {
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(ptr)+0x5c) = val;
}

