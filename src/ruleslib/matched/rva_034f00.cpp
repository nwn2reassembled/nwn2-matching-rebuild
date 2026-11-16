struct Legacy {
    static void __stdcall SetByte(void* ptr, unsigned char val);
};

void Legacy::SetByte(void* ptr, unsigned char val) {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+3) = val;
}

