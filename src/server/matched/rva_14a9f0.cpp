struct Legacy {
    int dummy;
    int value;

    int compute() const;
};

int Legacy::compute() const { return this->value + 0x1015c; }
