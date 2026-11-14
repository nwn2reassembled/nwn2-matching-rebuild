struct Legacy { static unsigned long __stdcall getField(const void* ptr); };

unsigned long Legacy::getField(const void* ptr) {
    return *(const unsigned long*)((const char*)ptr + 0xd0);
}

