struct Legacy {
    int placeholder;
    int value;

    unsigned char isNonZero() const;
};

unsigned char Legacy::isNonZero() const {
    return this->value != 0;
}

