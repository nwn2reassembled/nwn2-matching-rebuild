class Legacy {
public:
    static unsigned char __stdcall getByteAtOffset1(void* ptr);
};

unsigned char Legacy::getByteAtOffset1(void* ptr) {
    unsigned char* p = reinterpret_cast<unsigned char*>(ptr);
    return *(p + 1);
}

