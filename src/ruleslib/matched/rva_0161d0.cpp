struct MyClass {
    short lookup(unsigned int idx);
};

short MyClass::lookup(unsigned int idx) {
    if (idx <= 0x1a)
        return *reinterpret_cast<short*>(reinterpret_cast<char*>(this)+0x3e + idx*2);
    else
        return -1;
}
