struct Legacy {
    unsigned int getValue(void* ptr);
};

unsigned int Legacy::getValue(void* ptr) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x1ec);
}

