struct MyClass {
    unsigned int getValue() const;
};

unsigned int MyClass::getValue() const {
    const unsigned char* base = reinterpret_cast<const unsigned char*>(this);
    unsigned int idx = *(base + 0x36a);
    const unsigned int* arr = reinterpret_cast<const unsigned int*>(base + 0x320);
    return arr[idx];
}
