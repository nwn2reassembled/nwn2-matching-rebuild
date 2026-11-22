class Legacy {
public:
    unsigned int getValue(const void* ptr) const;
};

unsigned int Legacy::getValue(const void* ptr) const {
    return *reinterpret_cast<const unsigned int*>( reinterpret_cast<const char*>(ptr) + 0x224 );
}

