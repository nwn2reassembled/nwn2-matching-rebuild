class MyClass {
public:
    unsigned char getByte();
};

unsigned char MyClass::getByte() {
    return *(unsigned char*)((char*)this + 0xa1);
}

