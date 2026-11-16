class MyClass {
public:
    // Use the stdcall calling convention to emit a ret 0x4
    static unsigned short __stdcall getValue(const void* ptr);
};

unsigned short MyClass::getValue(const void* ptr) {
    const char* base = reinterpret_cast<const char*>(ptr);
    return *reinterpret_cast<const unsigned short*>(base + 12);
}
