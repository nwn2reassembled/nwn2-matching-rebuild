class MyClass {
public:
    static unsigned short __stdcall getValue(void* p);
};

unsigned short MyClass::getValue(void* p) {
    return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(p)+0x58);
}

