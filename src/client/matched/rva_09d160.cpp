class MyClass {
public:
    void* getOffset();
};

void* MyClass::getOffset() {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x17c);
}

