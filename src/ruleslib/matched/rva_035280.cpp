struct Legacy {
    static void __stdcall StoreWord(void* ptr, unsigned short val);
};

void Legacy::StoreWord(void* ptr, unsigned short val) {
    *reinterpret_cast<unsigned short*>(static_cast<char*>(ptr)+0x24) = val;
}

