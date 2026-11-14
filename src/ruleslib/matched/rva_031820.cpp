struct MyClass {
    short getWord(void*);
};

short MyClass::getWord(void* p) {
    return *reinterpret_cast<short*>(reinterpret_cast<char*>(p)+0x61C);
}
