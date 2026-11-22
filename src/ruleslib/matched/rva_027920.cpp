class Legacy {
public:
    signed char readByte(const void* arg) const;
};

signed char Legacy::readByte(const void* arg) const {
    const unsigned char* p = static_cast<const unsigned char*>(arg);
    return static_cast<signed char>(p[0x52]);
}
