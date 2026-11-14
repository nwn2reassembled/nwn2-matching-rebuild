class Legacy {
public:
    unsigned int getField(void* ptr);
};

unsigned int Legacy::getField(void* ptr) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr) + 0xDC);
}
