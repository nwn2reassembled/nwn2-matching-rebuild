class Legacy {
public:
    unsigned char getByte(unsigned char idx);
private:
    char pad[43];
    unsigned char table[41];
};

unsigned char Legacy::getByte(unsigned char idx) {
    unsigned char tmp = idx - 1;
    if (tmp <= 39u)
        return table[idx];
    return 0;
}
