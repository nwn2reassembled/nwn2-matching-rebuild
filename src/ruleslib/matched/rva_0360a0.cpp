struct MyClass {
    int check(const void* ptr, unsigned short val);
};

int MyClass::check(const void* ptr, unsigned short val) {
    const unsigned char* p = reinterpret_cast<const unsigned char*>(ptr);
    unsigned char byte = p[0x15a];
    return (val < byte) ? 1 : 0;
}

