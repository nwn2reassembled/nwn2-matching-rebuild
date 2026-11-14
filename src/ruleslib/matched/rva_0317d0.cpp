class MyClass {
public:
    static void __stdcall setWord(void* ptr, short value);
};

void MyClass::setWord(void* ptr, short value) {
    *(short*)((char*)ptr + 0x61a) = value;
}
