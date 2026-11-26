struct Legacy {
    int method(int* ptr);
};

int Legacy::method(int* ptr) {
    *ptr = 0x10;
    return 1;
}

