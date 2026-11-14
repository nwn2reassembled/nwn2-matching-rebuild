struct MyClass {
    int dummy;
    static void __stdcall foo(void* base, int offset, unsigned char value);
};

void MyClass::foo(void* base, int offset, unsigned char value) {
    *(unsigned char*)((char*)base + offset + 0x24) = value;
}

