class Legacy {
public:
    static int __stdcall getOffset(const void* ptr);
};

int __stdcall Legacy::getOffset(const void* ptr) {
    return *reinterpret_cast<const int*>(static_cast<const char*>(ptr)+0xC4);
}
