class Legacy {
public:
    unsigned char getByte(const void* arg);
};

unsigned char Legacy::getByte(const void* arg) {
    return *(const unsigned char*)((const char*)arg + 0x79);
}

