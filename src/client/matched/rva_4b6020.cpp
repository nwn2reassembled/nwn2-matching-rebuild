struct Legacy {
    int dummy;
    unsigned char flag1;
    unsigned char flag2;
    void clear();
};

void Legacy::clear() {
    flag1 = 0;
    flag2 = 0;
}

