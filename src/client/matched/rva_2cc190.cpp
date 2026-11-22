struct Legacy {
    int dummy;
    int value;
    int get() const;
};

int Legacy::get() const {
    return value + 0x2b8;
}

