struct Legacy {
    unsigned int getField(unsigned int ptr);
};

unsigned int Legacy::getField(unsigned int ptr) {
    return *reinterpret_cast<unsigned int*>(ptr + 0x248);
}
