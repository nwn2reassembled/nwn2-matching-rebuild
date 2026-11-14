struct TableReader {
    static unsigned short __stdcall readWord(const void* base, unsigned char index);
};

unsigned short TableReader::readWord(const void* base, unsigned char index) {
    const unsigned char* ptr = static_cast<const unsigned char*>(base);
    return *reinterpret_cast<const unsigned short*>(ptr + (index * 24u) + 0x460);
}

