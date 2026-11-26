struct MyClass {
    virtual ~MyClass() {}
    void* ptr;
    unsigned int getValue();
};

unsigned int MyClass::getValue()
{
    return *reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const char*>(ptr) + 0x10068);
}
