struct Legacy {
    unsigned char foo(unsigned char a, unsigned char b);
};

unsigned char Legacy::foo(unsigned char a, unsigned char b) {
    unsigned char result = 0;
    switch (a) {
    case 1:
        if ((unsigned char)(b - 1) <= 39)
            result = ((const unsigned char*)this)[0x55 + b];
        else
            result = 0;
        break;
    case 2:
        if ((unsigned char)(b - 1) <= 39)
            result = ((const unsigned char*)this)[0xa5 + b];
        else
            result = 0;
        break;
    case 3:
        if ((unsigned char)(b - 1) <= 39)
            result = ((const unsigned char*)this)[0x7d + b];
        else
            result = 0;
        break;
    }
    return result;
}
