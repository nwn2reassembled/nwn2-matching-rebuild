class Legacy {
public:
    static short __stdcall getField(void* ptr);
};

short Legacy::getField(void* ptr) {
    return *reinterpret_cast<short const*>(reinterpret_cast<char const*>(ptr)+0x61a);
}

