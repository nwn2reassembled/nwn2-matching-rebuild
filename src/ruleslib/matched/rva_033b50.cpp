class Legacy {
public:
    unsigned int getByte(const void* p) const;
};

unsigned int Legacy::getByte(const void* p) const {
    return static_cast<unsigned int>(static_cast<const unsigned char*>(p)[5]);
}

