class Legacy {
public:
    static unsigned int __stdcall getValue(void* ptr);
};

unsigned int Legacy::getValue(void* ptr) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x40);
}
