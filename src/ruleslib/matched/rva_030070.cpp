struct MyClass {
    static unsigned short __stdcall getValue(void* ptr);
};

unsigned short __stdcall MyClass::getValue(void* ptr) {
    return *reinterpret_cast<const unsigned short*>(static_cast<char*>(ptr)+0x6a);
}

