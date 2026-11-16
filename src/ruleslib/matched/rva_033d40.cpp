struct Legacy {
    int member;
    int compute(int arg);
};

int Legacy::compute(int arg) { return arg + 0x5b8; }
