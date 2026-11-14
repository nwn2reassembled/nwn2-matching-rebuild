struct Legacy {
    unsigned long GetOffset(void* ptr);
};

unsigned long Legacy::GetOffset(void* ptr) {
    return *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(ptr)+0x238);
}

