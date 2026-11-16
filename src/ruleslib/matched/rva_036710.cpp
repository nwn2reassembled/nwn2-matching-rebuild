struct Legacy { static unsigned char __stdcall getByte(unsigned char* ptr); };

unsigned char Legacy::getByte(unsigned char* ptr) {
    return *(ptr + 7);
}

