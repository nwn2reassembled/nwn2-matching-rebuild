struct MyClass {
    unsigned char padding0[188];
    unsigned short* table;
    unsigned char threshold;
    short func(unsigned char);
};

short MyClass::func(unsigned char param) {
    if (param >= threshold)
        return -1;
    return static_cast<short>(table[param]);
}
