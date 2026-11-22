class MyClass {
    int dummy;
public:
    unsigned long getValue() const;
private:
    void* ptr; // offset 4
};

unsigned long MyClass::getValue() const {
    return *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(ptr) + 0x10058);
}
