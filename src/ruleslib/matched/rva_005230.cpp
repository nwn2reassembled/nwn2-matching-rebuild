struct MyObj {
    virtual int func() const;
    int value;
};

int MyObj::func() const {
    if (value == 0xe) return 1;
    if (value == 0x38) return 1;
    if (value == 0x39) return 1;
    return 0;
}
