struct Legacy {
    int dummy;
    int value;
    int compute() const;
};
int Legacy::compute() const { return value + 0x70; }
