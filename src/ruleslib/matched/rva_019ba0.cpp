class Legacy {
public:
    unsigned char func(signed char);
};

unsigned char Legacy::func(signed char value) {
    if (value < 0xe)
        return 1;
    unsigned char result = value >= 0x10;
    result += 2;
    return result;
}
