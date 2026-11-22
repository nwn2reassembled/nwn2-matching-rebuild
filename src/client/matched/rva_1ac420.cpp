struct Legacy {
    unsigned member;
    unsigned check(unsigned);
};

unsigned Legacy::check(unsigned x) { return (x <= 14u) ? 1 : 0; }
