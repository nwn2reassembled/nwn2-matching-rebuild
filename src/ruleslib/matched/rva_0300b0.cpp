struct Legacy {
    static short __stdcall getField(Legacy* ptr);
};

short Legacy::getField(Legacy* ptr) {
    return *(short*)((char*)ptr + 0x70);
}

