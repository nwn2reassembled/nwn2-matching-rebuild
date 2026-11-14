class Legacy {
public:
    unsigned short getWord(void* ptr);
};

unsigned short Legacy::getWord(void* ptr) {
    return *reinterpret_cast<unsigned short*>(ptr);
}
