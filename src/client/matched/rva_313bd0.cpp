struct Legacy {
    char padding[0xc8];
    int value;
    void setZero();
};

void Legacy::setZero() {
    value = 0;
}

