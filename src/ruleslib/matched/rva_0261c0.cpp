class MyClass {
public:
    static unsigned long __stdcall GetField(void* p);
};

unsigned long MyClass::GetField(void* p) {
    return *reinterpret_cast<unsigned long*>(static_cast<char*>(p)+0x1b0);
}
