class Legacy {
public:
    unsigned char foo(unsigned char arg);
};

unsigned char Legacy::foo(unsigned char arg) {
    unsigned char result = 0;
    if (arg == 4)
        result = 1;
    else if (arg == 5)
        result = 2;
    else if (arg == 7)
        result = 3;
    else if (arg == 8)
        result = 4;
    else if (arg == 11)
        result = 5;
    else if (arg == 6)
        result = 8;
    else if (arg == 9)
        result = arg;
    return result;
}
