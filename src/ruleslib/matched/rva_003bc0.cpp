struct Legacy {
    unsigned char pad[40];
    unsigned short data[10];
    unsigned char findIndex(unsigned short val);
};

unsigned char Legacy::findIndex(unsigned short val) {
    if (val != 0xffff) {
        for (unsigned char i = 0; i < 10; ++i) {
            if (data[i] == val) {
                return i;
            }
        }
    }
    return 0xff;
}
