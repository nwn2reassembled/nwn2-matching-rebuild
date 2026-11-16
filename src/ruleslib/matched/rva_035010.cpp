struct Legacy {
    static void __stdcall func(void* ptr, unsigned char value);
};

void Legacy::func(void* ptr, unsigned char value) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0x50) = value;
}

