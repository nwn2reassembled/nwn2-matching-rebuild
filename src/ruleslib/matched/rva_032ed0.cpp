class X {
public:
    unsigned char getByte(const void* p);
};

unsigned char X::getByte(const void* p) {
    return *reinterpret_cast<const unsigned char*>(static_cast<const char*>(p)+10);
}

