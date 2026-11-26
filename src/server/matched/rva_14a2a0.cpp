struct MyClass {
    char pad[4];
    void* ptr;
    unsigned int getValue() const;
};

unsigned int MyClass::getValue() const {
    return * (const unsigned int*) ((const char*)ptr + 0x1006c);
}

