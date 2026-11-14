struct MyClass {
    unsigned char getByte(void* p);
};

unsigned char MyClass::getByte(void* p) {
    return reinterpret_cast<unsigned char*>(p)[0x5be];
}
