class Legacy {
public:
    static int __stdcall getValue(void* ptr);
};

int Legacy::getValue(void* ptr) { return *reinterpret_cast<int*>(static_cast<char*>(ptr)+0x1c8); }
