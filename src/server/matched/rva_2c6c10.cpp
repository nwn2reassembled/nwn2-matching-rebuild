struct Legacy {
    unsigned check(unsigned val);
};

unsigned Legacy::check(unsigned val) {
    return (val <= 4u) ? 1u : 0u;
}

