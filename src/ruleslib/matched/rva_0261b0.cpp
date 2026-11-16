class Legacy {
public:
    static int __stdcall GetField(void* p);
};

int Legacy::GetField(void* p) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x1ac);
}
