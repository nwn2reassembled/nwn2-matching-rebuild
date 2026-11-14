class Legacy {
public:
    unsigned int readField(const void* arg);
};

unsigned int Legacy::readField(const void* arg) {
    const char* p = static_cast<const char*>(arg);
    return *reinterpret_cast<const unsigned int*>(p + 0x90);
}

