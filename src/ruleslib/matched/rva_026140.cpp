class Legacy {
public:
    unsigned long getValue(unsigned long ptr);
};

unsigned long Legacy::getValue(unsigned long ptr) {
    return *reinterpret_cast<unsigned long*>(ptr + 0x15c);
}
