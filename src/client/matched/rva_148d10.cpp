struct MyClass {
    int dummy;            // occupies offset 0‑3
    int* p;               // located at offset +4
    int getValue() const; // declaration
};

int MyClass::getValue() const { return *(int*)((char*)p + 0x10074); }
