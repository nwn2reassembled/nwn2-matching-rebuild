class MyClass {
public:
    static void __stdcall setWordAtOffset(void* ptr, unsigned short val);
};

void MyClass::setWordAtOffset(void* ptr, unsigned short val) {
    *(unsigned short*)((char*)ptr + 0x72) = val;
}

