struct Legacy {
    unsigned int getValue(const void* ptr);
};

unsigned int Legacy::getValue(const void* ptr) {
    return *reinterpret_cast<const unsigned int*>(static_cast<const char*>(ptr)+0xF4);
}
