class MyClass {
public:
    static unsigned long __stdcall getField(void *p);
};

unsigned long MyClass::getField(void *p) {
    return *(unsigned long*)((char*)p + 0x198);
}

