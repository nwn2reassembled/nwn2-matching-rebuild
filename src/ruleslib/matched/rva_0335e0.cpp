class Legacy {
public:
    short getField(void* ptr);
};

short Legacy::getField(void* ptr) {
    return *reinterpret_cast<short*>(reinterpret_cast<char*>(ptr)+0x34);
}

