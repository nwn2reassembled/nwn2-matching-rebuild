class Legacy {
public:
    unsigned int func(const void* ptr) const;
};

unsigned int Legacy::func(const void* ptr) const {
    return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(ptr)+0x624);
}

