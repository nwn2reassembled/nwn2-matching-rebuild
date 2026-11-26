struct Foo {
    unsigned char pad[0x15A];
    unsigned char count_15a;
    unsigned char pad_15b[0x11];
    void* table_16c;

    void* GetEntry(unsigned short index);
};

void* Foo::GetEntry(unsigned short index) {
    unsigned short count = this->count_15a;
    if (index < count) {
        return reinterpret_cast<void*>(reinterpret_cast<char*>(this->table_16c) + index * 0x6C);
    }
    return 0;
}
