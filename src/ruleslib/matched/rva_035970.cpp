class MyClass {
public:
    static unsigned char __stdcall GetByte(void* p);
};

unsigned char MyClass::GetByte(void* p) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(p)+0x164);
}

