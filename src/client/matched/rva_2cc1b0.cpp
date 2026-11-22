class MyClass {
public:
    unsigned long getValue() const;
private:
    int first_;        // occupies offset 0
    void* ptr_;        // occupies offset 4, matches [ecx+0x4]
};

unsigned long MyClass::getValue() const {
    return *reinterpret_cast<unsigned long const volatile*>(
               reinterpret_cast<const char*>(ptr_) + 0x2e4);
}

