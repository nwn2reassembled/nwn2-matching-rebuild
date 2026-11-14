class Legacy {
public:
    static unsigned long __stdcall getField(unsigned long *ptr);
};

unsigned long Legacy::getField(unsigned long *ptr) {
    return *(reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(ptr)+0x620));
}
