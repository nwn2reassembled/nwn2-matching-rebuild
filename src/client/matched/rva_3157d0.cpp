struct MyClass {
    unsigned int getValue(unsigned int idx);
};

unsigned int MyClass::getValue(unsigned int idx) {
    return *(unsigned int*)((char*)this + 0x46c + (idx << 4));
}
