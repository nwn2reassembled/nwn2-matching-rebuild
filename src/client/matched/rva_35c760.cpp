class MyClass {
public:
    void* getField();
};

void* MyClass::getField() {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 0x18C);
}

