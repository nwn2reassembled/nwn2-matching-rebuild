struct Legacy {
    int func(int, int*);
};

int Legacy::func(int /*unused*/, int* ptr) { *ptr = 0; return 0; }
