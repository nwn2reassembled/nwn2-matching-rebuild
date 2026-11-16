
class MyClass {
public:
    unsigned int getValue(void* p);
};

unsigned int MyClass::getValue(void* p) {
    // Access the 32‑bit value located at offset 0x1b8 from the object pointed to by p.
    return *(unsigned int*)((char*)p + 0x1b8);
}

