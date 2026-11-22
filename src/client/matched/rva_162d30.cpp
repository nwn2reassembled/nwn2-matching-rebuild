class MyClass {
public:
    const void* getPtr() const;
};

const void* MyClass::getPtr() const {
    return reinterpret_cast<const void*>(reinterpret_cast<const char*>(this) + 0x2e4);
}
