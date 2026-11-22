class Legacy {
public:
    unsigned int GetField(void* ptr);
};

unsigned int Legacy::GetField(void* ptr) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x50);
}
