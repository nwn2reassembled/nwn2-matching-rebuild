struct Legacy {
    unsigned test(unsigned);
};

unsigned Legacy::test(unsigned a) { return 6 >= a; }
