class Legacy {
public:
    unsigned short getField(void* ptr);
};

unsigned short Legacy::getField(void* ptr) {
    return *reinterpret_cast<unsigned short*>(static_cast<char*>(ptr)+0xE);
}
