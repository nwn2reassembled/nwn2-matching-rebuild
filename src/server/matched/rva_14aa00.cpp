struct MyClass {
    int dummy;
    void* ptr;
    void setFlag(unsigned char flag);
};

void MyClass::setFlag(unsigned char flag) {
    unsigned char* base = static_cast<unsigned char*>(ptr);
    base[0x1018c] = flag;
}

