struct Legacy {
    char pad[122];
    short field;
    unsigned char func() const;
};

unsigned char Legacy::func() const {
    short val = field;
    if (val <= 30)
        return 3;
    unsigned char result = val >= 70;
    ++result;
    return result;
}
