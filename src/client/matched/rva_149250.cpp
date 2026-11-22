struct MyClass {
    int dummy;          // offset 0
    void* ptr;          // offset 4 – matches [ecx+0x4]
    void setByte(unsigned char);
};

void MyClass::setByte(unsigned char value) {
    unsigned char* base = (unsigned char*)ptr;
    base[0x1018c] = value;   // store the byte at [eax+0x1018c]
}

