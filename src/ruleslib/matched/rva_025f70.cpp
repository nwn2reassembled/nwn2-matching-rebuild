struct Legacy {
    static unsigned int __stdcall getField(void* ptr);
};

unsigned int __stdcall Legacy::getField(void* ptr) {
    return *(unsigned int*)((char*)ptr + 0xe8);
}

