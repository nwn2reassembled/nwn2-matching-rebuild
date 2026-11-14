struct Legacy {
    unsigned char pad1[0x15a];
    unsigned char threshold;
    unsigned char pad2[0x11];
    unsigned long basePtr;
    unsigned long getValue(unsigned short index) const;
};

unsigned long Legacy::getValue(unsigned short index) const {
    unsigned char* ptr;
    if (index < threshold)
        ptr = (unsigned char*)(basePtr + (unsigned long)index * 108);
    else
        ptr = 0;
    return *(unsigned long*)(ptr + 0x64);
}
