struct Legacy {
    char pad0[56];
    int value;
    int setZeroAndReturn();
};

int Legacy::setZeroAndReturn() { value = 0; return 1; }
