struct MyClass {
    unsigned long getField(unsigned long *p);
};

unsigned long MyClass::getField(unsigned long *p) {
    return *(unsigned long*)((char*)p + 0x94);
}

