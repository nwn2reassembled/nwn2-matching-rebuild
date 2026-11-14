class Legacy {
public:
    static int __stdcall getOffset(void* arg);
};

int Legacy::getOffset(void* arg) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(arg)+0x44);
}
