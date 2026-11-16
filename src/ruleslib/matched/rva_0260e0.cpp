struct Legacy {
    static unsigned int __stdcall readValue(void* src);
};

unsigned int __stdcall Legacy::readValue(void* src) {
    return *(unsigned int*)((char*)src + 0x13c);
}

