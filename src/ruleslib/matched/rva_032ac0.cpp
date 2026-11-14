struct LegacyTable {
    static unsigned short __stdcall fetch(const void* tableBase, unsigned char index);
};

unsigned short __stdcall LegacyTable::fetch(const void* tableBase, unsigned char index) {
    const unsigned short* tbl = reinterpret_cast<const unsigned short*>(
        reinterpret_cast<const unsigned char*>(tableBase) + 0x28
    );
    return tbl[index];
}

