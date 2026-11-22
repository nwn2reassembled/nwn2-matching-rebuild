struct Legacy {
    unsigned char getValue(unsigned int ptr);
};

unsigned char Legacy::getValue(unsigned int ptr) {
    return *reinterpret_cast<unsigned char const*>(ptr + 0x7c);
}

