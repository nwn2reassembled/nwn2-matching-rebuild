class Legacy {
public:
    unsigned short readWord(void* ptr);
};

unsigned short Legacy::readWord(void* ptr) {
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(ptr)+8);
}
