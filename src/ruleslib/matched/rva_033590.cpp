struct Legacy {
    int readOffset(int*);
};

int Legacy::readOffset(int* p) { return *(int*)((char*)p + 0x10); }
