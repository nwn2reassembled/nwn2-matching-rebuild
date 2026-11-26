struct MyClass {
    char pad[0x48];
    unsigned long long data[10];
    void* getPtr(int idx);
};

void* MyClass::getPtr(int idx) {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + idx * 8 + 0x48);
}

