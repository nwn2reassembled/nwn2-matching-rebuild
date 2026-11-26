unsigned int GetDwordAtCB(const void* obj) {
    const unsigned char* base = (const unsigned char*)obj;
    return *(const unsigned int*)(base + 0xCB);
}
