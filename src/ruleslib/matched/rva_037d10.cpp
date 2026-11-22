class Legacy {
public:
    unsigned int getOffsetValue(unsigned int* ptr);
};

unsigned int Legacy::getOffsetValue(unsigned int* ptr) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x60);
}

