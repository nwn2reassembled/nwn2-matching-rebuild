struct Legacy {
    int set(int, int*);
};

int Legacy::set(int, int* p) {
    *p = 0x10;
    return 1;
}
