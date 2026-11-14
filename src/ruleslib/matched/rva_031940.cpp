class Legacy {
public:
    unsigned char readByte(int *p);
};

unsigned char Legacy::readByte(int *p) {
    return reinterpret_cast<char*>(p)[0x628];
}
