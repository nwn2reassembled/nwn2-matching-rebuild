class Legacy {
public:
    static int __stdcall GetValue(void* ptr);
};

int Legacy::GetValue(void* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x328);
}
