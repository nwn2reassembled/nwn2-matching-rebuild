struct MyClass {
    unsigned short getWordAtOffset(const void* ptr);
};

unsigned short MyClass::getWordAtOffset(const void* ptr) {
    return *reinterpret_cast<const unsigned short*>((const char*)ptr + 0x3c);
}
