struct Legacy {
    int check(int);
};

int Legacy::check(int value) {
    return !(static_cast<unsigned>(value) > 0x13u);
}
