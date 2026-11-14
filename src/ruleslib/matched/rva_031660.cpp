class Legacy {
public:
    static int __stdcall getField(void* ptr);
};

int Legacy::getField(void* ptr) {
    return *reinterpret_cast<int*>(static_cast<char*>(ptr)+0x608);
}

