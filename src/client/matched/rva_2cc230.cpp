struct Legacy {
    int unused;
    int value;
    int adjusted() const;
};

int Legacy::adjusted() const {
    return value + 0x150;
}
