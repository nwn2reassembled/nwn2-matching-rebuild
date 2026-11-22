class MyClass {
public:
    void* getOffset(int);
};

void* MyClass::getOffset(int index) {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + static_cast<int>(index) * 0xB4);
}

