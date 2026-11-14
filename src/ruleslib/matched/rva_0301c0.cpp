class MyClass {
public:
    static unsigned char __stdcall ReadByte(void* ptr);
};

unsigned char MyClass::ReadByte(void* ptr) {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(ptr)+0xAC);
}
