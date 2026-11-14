struct Legacy {
    char data[120];
    unsigned char legacyFunc();
};

unsigned char Legacy::legacyFunc() {
    unsigned short v = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 0x78);
    if ((short)v <= 30)
        return 5;
    unsigned char result = (short)v < 70;
    --result;
    result &= 3;
    ++result;
    return result;
}
