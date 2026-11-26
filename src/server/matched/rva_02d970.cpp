struct Legacy {
    int func() const;
};

int Legacy::func() const {
    unsigned char val = *reinterpret_cast<const unsigned char*>(0x8691e8);
    return (val == 0) ? 1 : 91;
}
