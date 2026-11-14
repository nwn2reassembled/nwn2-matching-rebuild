class Legacy {
public:
    unsigned long getValue(void* ptr);
};

unsigned long Legacy::getValue(void* ptr) {
    return *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(ptr) + 0x180);
}

