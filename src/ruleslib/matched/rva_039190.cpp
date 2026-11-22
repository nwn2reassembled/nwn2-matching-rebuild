struct Legacy {
    int compare(void* ptr, unsigned short val);
};

int Legacy::compare(void* ptr, unsigned short val) {
    return (val < *reinterpret_cast<int*>((char*)ptr + 0x1c)) ? 1 : 0;
}

