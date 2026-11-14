struct Legacy {
    static unsigned int __stdcall getField(const void* ptr);
};

unsigned int Legacy::getField(const void* ptr) {
    return *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(ptr)+0x74);
}
