class Legacy {
public:
    unsigned int getField(const void* ptr) const;
};

unsigned int Legacy::getField(const void* ptr) const {
    return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(ptr)+0x320);
}

