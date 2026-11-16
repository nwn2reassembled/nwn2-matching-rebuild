class MyClass {
public:
    unsigned func();
};

unsigned MyClass::func() {
    return *(const unsigned*)((char*)this + 0x18) + *(const unsigned*)((char*)this + 0xc) + 1;
}

