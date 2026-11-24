struct MyClass {
    void* getPtr();
};

void* MyClass::getPtr() {
    return reinterpret_cast<void*>(reinterpret_cast<char*>(this) + 4);
}
