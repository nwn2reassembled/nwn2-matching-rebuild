struct MyStruct {
    char* getOffset(unsigned int idx);
};

char* MyStruct::getOffset(unsigned int idx) {
    unsigned long *field = reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this)+0xc0);
    unsigned long base = *field;
    return reinterpret_cast<char*>(base + (idx << 6) + 0x30);
}
