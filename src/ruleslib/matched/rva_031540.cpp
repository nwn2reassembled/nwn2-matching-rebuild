class MyClass {
public:
    static unsigned int __stdcall GetFieldAtOffset(void* ptr);
};

unsigned int MyClass::GetFieldAtOffset(void* ptr) {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(ptr)+0x5f8);
}

