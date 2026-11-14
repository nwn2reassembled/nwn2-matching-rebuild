struct Legacy {
    int fetch(int* p) const;
};

int Legacy::fetch(int* p) const {
    return *(int*)((char*)p + 0x5c0);
}
